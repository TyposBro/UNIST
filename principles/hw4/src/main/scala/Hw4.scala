package hw4

import scala.collection.immutable.HashMap 
import hw4._


package object hw4 {
  type Env = HashMap[Var,LocVal]
  }

case class Mem(m: HashMap[LocVal,Val], top: Int) {
  def extended(v: Val): (Mem, LocVal) = {
    val new_mem = Mem(m.updated(LocVal(top),v), top+1)
    (new_mem,LocVal(top))
    }
  def updated(l: LocVal, new_val: Val): Option[Mem] = {
    m.get(l) match {
      case Some(v) => Some(Mem(m.updated(l, new_val), top))
      case None => None}}
  def get(l: LocVal): Option[Val] = m.get(l)
  def getLocs(): List[LocVal] = m.keySet.toList}

sealed trait Val
case object SkipVal extends Val
case class IntVal(n: Int) extends Val
case class BoolVal(b: Boolean) extends Val
case class ProcVal(args: List[Var], expr: Expr, env: Env) extends Val
case class LocVal(l: Int) extends Val
sealed trait RecordValLike extends Val
case object EmptyRecordVal extends RecordValLike
case class RecordVal(field: Var, loc: LocVal, next: RecordValLike) extends RecordValLike


sealed trait Program
sealed trait Expr extends Program
case object Skip extends Expr
case object False extends Expr
case object True extends Expr
case class NotExpr(expr: Expr) extends Expr
case class Const(n: Int) extends Expr
case class Var(s: String) extends Expr {
  override def toString = s"Var(${"\""}${s}${"\""})"}
case class Add(l: Expr, r: Expr) extends Expr
case class Sub(l: Expr, r: Expr) extends Expr
case class Mul(l: Expr, r: Expr) extends Expr
case class Div(l: Expr, r: Expr) extends Expr
case class LTEExpr(l: Expr, r: Expr) extends Expr
case class EQExpr(l: Expr, r: Expr) extends Expr
case class Iszero(c: Expr) extends Expr
case class Ite(c: Expr, t: Expr, f: Expr) extends Expr
case class Let(i: Var, v: Expr, body: Expr) extends Expr
case class Proc(args: List[Var], expr: Expr) extends Expr
case class Asn(v: Var, e: Expr) extends Expr
case class BeginEnd(expr: Expr) extends Expr
case class FieldAccess(record: Expr, field: Var) extends Expr
case class FieldAssign(record: Expr, field: Var, new_val: Expr) extends Expr
case class Block(f: Expr, s: Expr) extends Expr
case class PCallV(ftn: Expr, arg: List[Expr]) extends Expr
case class PCallR(ftn: Expr, arg: List[Var]) extends Expr
case class WhileExpr(cond: Expr, body: Expr) extends Expr
sealed trait RecordLike extends Expr
case object EmptyRecordExpr extends RecordLike
case class RecordExpr(field: Var, initVal: Expr, next: RecordLike) extends RecordLike


object MiniCInterpreter {
  case class Result(v: Val, m: Mem)
  case class UndefinedSemantics(msg: String = "", cause: Throwable = None.orNull) extends Exception("Undefined Semantics: " ++ msg, cause)
    
  def eval(env: Env, mem: Mem, expr: Expr): Result = expr match{
    case Skip => Result(SkipVal, mem)
    case False => Result(BoolVal(false), mem)
    case True => Result(BoolVal(true), mem)
    case NotExpr(expr: Expr) => {
      val a = eval(env, mem, expr)
      a.v match {
        case BoolVal(b) => Result(BoolVal(if (b) false else true), a.m)
        case _ => throw new UndefinedSemantics("not defined")
        }
      }





      
    case Const(n:Int) => Result(IntVal(n), mem)
    case Var(s: String) => env.get(Var(s)) match {
      case Some(v) => v match {
        case r: LocVal => mem.get(r) match {
          case Some(v) => Result(v,mem)
          case _ => throw new UndefinedSemantics(s"the location ${r} for ${s} is not allocated")}
        case _ => Result(v,mem)}
      case None => throw new UndefinedSemantics(s"${s} is undefined")}
    case Add(l: Expr, r: Expr) =>{
      val r1 = eval(env,mem,l)
      val r2 = eval(env,r1.m, r)
      (r1.v, r2.v) match {
        case (v1: IntVal, v2: IntVal) => Result(IntVal(v1.n + v2.n), r2.m)
        case _ => throw new UndefinedSemantics("can add integer to another only")}}
    case Sub(l: Expr, r: Expr) =>{
      val r1 = eval(env,mem,l)
      val r2 = eval(env,r1.m, r)
      (r1.v, r2.v) match {
        case (v1: IntVal, v2: IntVal) => Result(IntVal(v1.n - v2.n), r2.m)
        case _ => throw new UndefinedSemantics("can subtract integer from integer only")}}
    case Mul(l: Expr, r: Expr) =>{
      val r1 = eval(env,mem,l)
      val r2 = eval(env,r1.m, r)
      (r1.v, r2.v) match {
        case (v1: IntVal, v2: IntVal) => Result(IntVal(v1.n * v2.n), r2.m)
        case _ => throw new UndefinedSemantics("can multiply integer by integer only")}}
    case Div(l: Expr, r: Expr) =>{
      val r1 = eval(env,mem,l)
      val r2 = eval(env,r1.m, r)
      (r1.v, r2.v) match {
        case (_, IntVal(0)) => throw new UndefinedSemantics("Divide by zero")
        case (v1: IntVal, v2: IntVal) => Result(IntVal(v1.n / v2.n), r2.m)
        case _ => throw new UndefinedSemantics("can divide integer by integer only")}}
    case LTEExpr(l: Expr, r: Expr) => {
      val r1 = eval(env, mem, l)
      val r2 = eval(env, r1.m, r)
      (r1.v, r2.v) match {
        case (a: IntVal, b: IntVal) => Result(BoolVal(a.n <= b.n), r2.m)
        case _ => throw new UndefinedSemantics("undefined")}}
    case EQExpr(l: Expr, r: Expr) => {
      val r1 = eval(env, mem, l)
      val r2 = eval(env, r1.m, r)
      (r1.v, r2.v) match {
        case (a: IntVal, b: IntVal) => Result(BoolVal(a.n == b.n), r2.m)
        case (a: BoolVal, b: BoolVal) => Result(BoolVal(a.b == b.b), r2.m)
        case (a: RecordValLike, b: RecordValLike) => Result(BoolVal(compareRV(a, b)), r2.m)
        case _ => throw new UndefinedSemantics("undefined")}}
    case Iszero(c:Expr) =>{
      val r = eval(env,mem,c)
      r.v match {
      case x: IntVal => Result(BoolVal(x.n == 0), r.m)
      case _ => throw new UndefinedSemantics("can iszero with integer only")}}
    case Ite(c: Expr, t: Expr, f: Expr) => eval(env,mem,c) match {
      case Result(v: BoolVal,m) => if (v.b) eval(env,m,t) else eval(env,m,f)
      case _ => throw new UndefinedSemantics("condition should be Boolean")}
    case Let(i: Var, v: Expr, body: Expr) => {
      val r = eval(env, mem, v)
      val nm = r.m.extended(r.v)
      eval(env.updated(i, nm._2), nm._1, body)}
    case Proc(args: List[Var], expr: Expr) => Result(ProcVal(args, expr, env), mem)
    case Asn(v: Var, e: Expr) =>{
      val r = eval(env,mem,e)
      env.get(v) match {
        case Some(v: LocVal) => r.m.updated(v,r.v) match {
          case Some(new_mem) => Result(r.v, new_mem)
          case _ => throw new UndefinedSemantics(s"location for variable is not allocated")}
        case Some(_) => throw new UndefinedSemantics(s"variable is not mutable")
        case None => throw new UndefinedSemantics(s"variable is not defined")}}
    case BeginEnd(expr: Expr) => eval(env, mem, expr)
    case FieldAccess(record: Expr, field: Var) => {
      val r1 = eval(env, mem, record)
      val r2 = r1.v match {
        case a: RecordVal => find(a, field)
        case _ => throw new UndefinedSemantics("undefined")}
      r2 match {
        case Some(v: LocVal) => r1.m.get(v) match {
          case Some(vv: Val) => Result(vv, r1.m) 
          case _ => throw new UndefinedSemantics("undefined")} 
        case None => throw new UndefinedSemantics("undefined")}}     
    case FieldAssign(record: Expr, field: Var, new_val: Expr) => {
      val r1 = eval(env, mem, record)
      val r2 = eval(env, r1.m, new_val)
      val r3 = r1.v match {
        case a: RecordVal => find(a, field)
        case _ => throw new UndefinedSemantics("undefined")}
      r3 match {
        case Some(v: LocVal) => {
          r2.m.updated(v, r2.v) match {
            case Some(v1) => Result(r2.v, v1)
            case None => throw new UndefinedSemantics("undefined")}} 
        case None => throw new UndefinedSemantics("undefined")}}
    case Block(f: Expr, s: Expr) =>{
      val r1 = eval(env,mem,f)
      eval(env,r1.m,s)}
    case PCallV(ftn: Expr, arg: List[Expr]) => {
      val r1 = eval(env, mem, ftn)
      r1.v match {
        case p: ProcVal => {
          val r2 = putArg(p.env, env, r1.m, p.args, arg)
          eval(r2._1, r2._2, p.expr)}
        case _ => throw new UndefinedSemantics("undefined")}}
    case PCallR(ftn: Expr, arg: List[Var]) => {
      val r1 = eval(env, mem, ftn)
      r1.v match {
        case p: ProcVal => {
          (p.args, arg) match {
            case (pF :: pR, ftn :: re) => {
              val r3 = Proc(pR, p.expr)
              val r4 = env.get(ftn) match {
                case Some(v) => v
                case None => throw new UndefinedSemantics("undefined")}
              eval(env.updated(pF, r4), r1.m, PCallR(r3, re))} 
            case (Nil, Nil) => {
              eval(p.env, r1.m, p.expr)}
            case _ => throw new UndefinedSemantics("undefined")}}
        case _ => throw new UndefinedSemantics("undefined") }}
    case WhileExpr(cond: Expr, body: Expr) => {
      val r1 = eval(env, mem, cond)
      r1.v match {
        case BoolVal(b: Boolean) => 
          if (b) {
            val r2 = eval(env, r1.m, body)
            eval(env, r2.m, WhileExpr(cond, body))}
          else Result(SkipVal, r1.m)
        case _ => throw new UndefinedSemantics("undefined")}}
    case EmptyRecordExpr => Result(EmptyRecordVal, mem)
    case RecordExpr(field: Var, initVal: Expr, next: RecordLike) => {
      val r1 = eval(env, mem, initVal)
      val r2 = r1.m.extended(r1.v)
      val r3 = eval(env, r2._1, next)
      r3.v match {
        case a: RecordValLike => Result(RecordVal(field, r2._2, a), r3.m)
        case _ => throw new UndefinedSemantics("undefined")}}

    case _ => throw new Exception()}

  def compareRV(l: RecordValLike, r: RecordValLike): Boolean ={
    (l,r) match {
      case (RecordVal(rf,rl,rn), RecordVal(lf, ll, ln)) => 
        rf == lf && rl.isInstanceOf[LocVal] && ll.isInstanceOf[LocVal] && compareRV(rn, ln)
      case (EmptyRecordVal,EmptyRecordVal) => true
      case _ => false}}

  def putArg(b1: Env, b2: Env, m: Mem, a1: List[Var], a2: List[Expr]): (Env, Mem) ={
    (a1, a2) match {
      case (pF :: pR, f :: r) =>{
        val r1 = eval(b2, m, f)
        val r2 = r1.m.extended(r1.v)
        putArg(b1.updated(pF, r2._2), b2, r2._1, pR, r)}
      case (Nil, Nil) => {(b1, m)}
      case _ => throw new UndefinedSemantics("undefined")}}

  def find(b1: RecordValLike, b2: Var): Option[LocVal] ={
    b1 match {
      case RecordVal(f, l, n) =>{
        if (b2 == f) Some(l)
        else find(n, b2)}
      case EmptyRecordVal => None}}

  def gc(env: Env, mem: Mem): Mem ={
    if (env.isEmpty) Mem(new HashMap[LocVal,Val], mem.top)
    else {
      val a = env.head._1 
      val b = env.head._2
      val c = env-a
      val d = gc(c, mem)
      mem.get(b) match {
        case Some(vv: RecordValLike) => vv match {
          case v1: RecordVal => {
            val r1 = gc(c + (a -> v1.loc), mem)
            Mem(r1.m + (b -> vv), d.top)}
          case _ => d}
        case Some(vv: LocVal) =>{
          val r1 = gc(c + (a -> vv), mem)
          Mem(r1.m + (b-> vv), d.top)}
        case Some(vv) => Mem(d.m + (b-> vv), d.top)
        case None => d}}}
  
  def apply(program: String): (Val, Mem) ={
    val parsed = MiniCParserDriver(program)
    val res = eval(new Env(), Mem(new HashMap[LocVal,Val],0), parsed)
    (res.v, res.m)}}

object Hw4App extends App {println("Hello from Hw4!")}