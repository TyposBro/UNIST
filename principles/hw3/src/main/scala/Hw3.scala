package hw3

import scala.collection.immutable.HashMap 
import hw3._

package object hw3 {
  type Env = HashMap[Var,Val]
  type Loc = Int}

case class Mem(m: HashMap[Loc,Val], top: Loc){
  def extended(v: Val): (Mem, LocVal) ={
    val n_mem = Mem(m.updated(top,v), top+1)
    (n_mem,LocVal(top))}
  def updated(l: LocVal, n_val: Val): Option[Mem] ={
    m.get(l.l) match {
      case Some(v) => Some(Mem(m.updated(l.l, n_val), top))
      case None => None}}
  def get(l: LocVal): Option[Val] = m.get(l.l)}


sealed trait Val
case class IntVal(n: Int) extends Val
case class BoolVal(b: Boolean) extends Val
case class ProcVal(v: Var, expr: Expr, env: Env) extends Val
case class RecProcVal(fv: Var, av: Var, body: Expr, env: Env) extends Val
case class LocVal(l: Loc) extends Val


sealed trait Program
sealed trait Expr extends Program
case class Const(n: Int) extends Expr
case class Var(s: String) extends Expr
case class Add(l: Expr, r: Expr) extends Expr
case class Sub(l: Expr, r: Expr) extends Expr
case class Mul(l: Expr, r: Expr) extends Expr
case class Div(l: Expr, r: Expr) extends Expr
case class GTExpr(l: Expr, r: Expr) extends Expr
case class GEQExpr(l: Expr, r: Expr) extends Expr
case class Iszero(c: Expr) extends Expr
case class Ite(c: Expr, t: Expr, f: Expr) extends Expr
case class ValExpr(name: Var, value: Expr, body: Expr) extends Expr
case class VarExpr(name: Var, value: Expr, body: Expr) extends Expr
case class Proc(v: Var, expr: Expr) extends Expr
case class DefExpr(fname: Var, aname: Var, fbody: Expr, ibody: Expr) extends Expr
case class Asn(v: Var, e: Expr) extends Expr
case class Paren(expr: Expr) extends Expr
case class Block(f: Expr, s: Expr) extends Expr
case class PCall(ftn: Expr, arg: Expr) extends Expr


object MiniScalaInterpreter {

  case class Result(v: Val, m: Mem)
  case class UndefinedSemantics(msg: String = "", cause: Throwable = None.orNull) extends Exception("Undefined Semantics: " ++ msg, cause)
  
  def doInterpret(env: Env, mem: Mem, expr: Expr): Result = expr match{
    case Const(n: Int) => Result(IntVal(n),mem)
    case Var(s: String) => env.get(Var(s)) match {
      case Some(v) => v match {
        case r: LocVal => mem.get(r) match {
          case Some(v) => Result(v,mem)
          case _ => throw new UndefinedSemantics(s"the location ${r} for ${s} is not allocated")}
        case _ => Result(v,mem)}
      case None => throw new UndefinedSemantics(s"${s} is undefined")}     
    case Add(l: Expr, r: Expr) =>{
      val left = doInterpret(env,mem,l)
      val right = doInterpret(env,left.m, r)
      (left.v, right.v) match {
        case (vl: IntVal, vr: IntVal) => Result(IntVal(vl.n + vr.n), right.m)
        case _ => throw new UndefinedSemantics("can add integer to another only")}}
    case Sub(l: Expr, r: Expr) =>{
      val left = doInterpret(env,mem,l)
      val right = doInterpret(env,left.m, r)
      (left.v, right.v) match {
        case (vl: IntVal, vr: IntVal) => Result(IntVal(vl.n - vr.n), right.m)
        case _ => throw new UndefinedSemantics("can subtract integer from integer only")}}
    case Mul(l: Expr, r: Expr) =>{
      val left = doInterpret(env,mem,l)
      val right = doInterpret(env,left.m, r)
      (left.v, right.v) match {
        case (vl: IntVal, vr: IntVal) => Result(IntVal(vl.n * vr.n), right.m)
        case _ => throw new UndefinedSemantics("can multiply integer by integer only")}}
    case Div(l: Expr, r: Expr) =>{
      val left = doInterpret(env,mem,l)
      val right = doInterpret(env,left.m, r)
      (left.v, right.v) match {
        case (_, IntVal(0)) => throw new UndefinedSemantics("Divide by zero")
        case (vl: IntVal, vr: IntVal) => Result(IntVal(vl.n / vr.n), right.m)
        case _ => throw new UndefinedSemantics("can divide integer by integer only")}}
    case GTExpr(l: Expr, r: Expr) =>{
      val left = doInterpret(env,mem,l)
      val right = doInterpret(env,left.m, r)
      (left.v, right.v) match {
        case (vl: IntVal, vr: IntVal) => Result(BoolVal(vl.n > vr.n), right.m)
        case _ => throw new UndefinedSemantics("can gt integer from another only")}}
    case GEQExpr(l: Expr, r: Expr) =>{
      val left = doInterpret(env,mem,l)
      val right = doInterpret(env,left.m,r)
      (left.v, right.v) match {
        case (vl: IntVal, vr: IntVal) => Result(BoolVal(vl.n >= vr.n), right.m)
        case _ => throw new UndefinedSemantics("can geq integer from another only")}}
    case Iszero(c:Expr) =>{
      val r = doInterpret(env,mem,c)
      r.v match {
      case x: IntVal => Result(BoolVal(x.n == 0), r.m)
      case _ => throw new UndefinedSemantics("can iszero with integer only")}}
    case Ite(c: Expr, t: Expr, f: Expr) => doInterpret(env,mem,c) match {
      case Result(v: BoolVal,m) => if (v.b) doInterpret(env,m,t) else doInterpret(env,m,f)
      case _ => throw new UndefinedSemantics("condition should be Boolean")}
    case ValExpr(name: Var, value: Expr, body: Expr) =>{
      val r = doInterpret(env,mem,value)
      val new_env = env.updated(name, r.v)
      doInterpret(new_env, r.m, body)}
    case VarExpr(name: Var, value: Expr, body: Expr) =>{
      val r = doInterpret(env,mem,value)
      val e = r.m.extended(r.v)
      val n_mem = e._1
      val loc = e._2
      val n_env = env.updated(name, e._2)
      doInterpret(n_env, n_mem, body)}
    case Asn(v: Var, e: Expr) =>{
      val r = doInterpret(env,mem,e)
      env.get(v) match {
        case Some(v: LocVal) => r.m.updated(v,r.v) match {
          case Some(new_mem) => Result(r.v, new_mem)
          case _ => throw new UndefinedSemantics(s"location for variable is not allocated")}
        case Some(_) => throw new UndefinedSemantics(s"variable is not mutable")
        case None => throw new UndefinedSemantics(s"variable is not defined")}}
    case Paren(expr: Expr) => doInterpret(env,mem,expr)
    case Block(f: Expr, s: Expr) =>{
      val res = doInterpret(env,mem,f)
      doInterpret(env,res.m,s)}
    case Proc(v: Var, expr: Expr) =>Result(ProcVal(v,expr,env),mem)
    case PCall(ftn: Expr, arg: Expr) =>{
      val proc = doInterpret(env,mem,ftn)
      val ar = doInterpret(env,proc.m,arg)
      proc.v match {
        case p: ProcVal =>{
          val n_env = p.env.updated(p.v, ar.v)
          doInterpret(n_env, ar.m, p.expr)  }
        case rp: RecProcVal =>{
          val n_env = rp.env.updated(rp.fv, rp).updated(rp.av, ar.v)
          doInterpret(n_env, ar.m, rp.body)}
        case _ => throw new Exception("Error")}}
    case DefExpr(fv,av,body,expr) => {
      val rp = RecProcVal(fv,av,body,env)
      val new_env = env.updated(fv, rp)
      doInterpret(new_env,mem,expr)}
    case _=> throw new Exception(s"expr not found")}
  
  def apply(program: String): Val = {
    val parsed = MiniScalaParserDriver(program)
    doInterpret(new Env(), Mem(new HashMap[Loc,Val],0), parsed).v}}


object Hw3App extends App {
  println("Hello from Hw3!")}