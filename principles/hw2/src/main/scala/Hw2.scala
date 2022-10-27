package Hw2

import fastparse._
import MultiLineWhitespace._
import scala.collection.immutable.HashMap 

sealed trait Val
case class IntVal(n: Int) extends Val
case class BoolVal(b: Boolean) extends Val
case class ProcVal(v: Var, expr: Expr, env: Env) extends Val
case class RecProcVal(fv: Var, av: Var, body: Expr, expr: Expr, env: Env) extends Val

case class Env(hashmap: HashMap[Var,Val]) {
  def apply(variable: Var): Val = hashmap(variable)
  def exists(v: Var): Boolean = 
    hashmap.exists((a: (Var, Val)) => a._1 == v)
  def add(v: Var, value: Val) = Env(hashmap + (v -> value))  
}

sealed trait Program
sealed trait Expr extends Program
case class Const(n: Int) extends Expr
case class Var(s: String) extends Expr
case class Add(l: Expr, r: Expr) extends Expr
case class Sub(l: Expr, r: Expr) extends Expr
case class Iszero(c: Expr) extends Expr
case class Ite(c: Expr, t: Expr, f: Expr) extends Expr
case class Let(name: Var, value: Expr, body: Expr) extends Expr
case class Paren(expr: Expr) extends Expr
case class Proc(v: Var, expr: Expr) extends Expr
case class PCall(ftn: Expr, arg: Expr) extends Expr
case class LetRec(fname: Var, aname: Var, fbody: Expr, ibody: Expr) extends Expr

sealed trait IntExpr
case class IntConst(n: Int) extends IntExpr
case object IntVar extends IntExpr
case class IntAdd(l: IntExpr, r: IntExpr) extends IntExpr
case class IntSub(l: IntExpr, r: IntExpr) extends IntExpr
case class IntMul(l: IntExpr, r: IntExpr) extends IntExpr
case class IntSigma(f: IntExpr, t: IntExpr, b: IntExpr) extends IntExpr
case class IntPow(b: IntExpr, e: IntExpr) extends IntExpr



package object Hw2 {

  

}

object IntInterpreter {
  //TODO: Start here 1st
  def pow(n:Int,m:Int):Int= {if (m!=0) n*pow(n, m-1) else 1}

  def evalInt(expr: IntExpr, env: Option[Int]): Int = 
  expr match {
    case IntConst(n) => n
    case IntVar=>env()
    case IntAdd(a,b)=>(evalInt(a, env), evalInt(b, env)) match {
      case (x: Int, y:Int) => x+y
      case _ => throw new Exception("Type Error")
    }
    case IntSub(a,b) => (evalInt(a, env), evalInt(b,env)) match {
      case (x: Int, y: Int) => x - y
      case _ => throw new Exception("Type Error")
    }

    case IntPow(a,b) => (evalInt(a, env), evalInt(b,env)) match {
      
      case (x: Int, y: Int) => pow(x,y)
      case _ => throw new Exception("Type Error")
    }    
  } 
  def apply(s: String): Int = {
    val parsed = IntParser(s)
    println(parsed)
    evalInt(parsed, None)
  }
}

object LetRecInterpreter {
  
  //TODO: 2nd
  def eval(env: Env, expr: Expr): Val = BoolVal(false)
  
  
  def apply(program: String): Val = {
    val parsed = LetRecParserDriver(program)
    eval(Env(new HashMap[Var,Val]()), parsed)
  }

}

object LetRecToString {
  //TODO: 3rd

  def apply(expr: Expr): String = "1"
}

object Hw2App extends App {
  
  println("Hello from Hw2!")

  val int_prog = """x + 1"""
  val parsed = IntParser(int_prog)
  println(parsed)


}