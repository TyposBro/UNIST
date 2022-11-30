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
  def evalInt(expr: IntExpr, env: Option[Int]): Int = expr match{
    case IntConst(n) => n
    case IntAdd(a,b) => (evalInt(a, env), evalInt(b, env)) match {
      case (x: Int, y: Int) => x + y
      case (_) => throw new Exception("Addition Error")
    }
     case IntMul(a,b) => (evalInt(a, env), evalInt(b, env)) match {
      case (x: Int, y: Int) => x * y
      case (_) => throw new Exception("Multiplication Error")
    }
    case IntSub(a,b) => (evalInt(a, env), evalInt(b, env)) match {
      case (x: Int, y: Int) => x - y
      case (_) => throw new Exception("Subtraction Error")
    }
   
     case IntSigma(a,b,f) => (evalInt(a, env), evalInt(b, env)) match {
      case (x: Int, y: Int) => computeSigma(x,y,f)
       
      case (_) => throw new Exception("Sigma function Error")
    }
    
    case IntPow(a,b) => (evalInt(a, env), evalInt(b, env)) match {
      case (x: Int, y: Int) => power(x,y)
      case (_) => throw new Exception("Power funct Error")
    }
    case (_) => throw new Exception("Error")
  }


    def power(x: Int, y:Int): Int = {
    if (y == 0) {
      return 1
    } 
    return x * power(x, y-1)
  }

  def apply(s: String): Int = {
    val parsed = IntParser(s)
    evalInt(parsed, None)
  }
  
   def computeSigma(x: Int, y: Int, f: IntExpr): Int = {
    val v = f match {
        case IntAdd(_,IntConst(n)) => n + x
        case IntAdd(_,_) => x + x
        case IntConst(n) => n
        case IntPow(_,IntConst(n)) => power(x,n)
        case _ => x
      } 
      if (x >= y) {
        return v
      } 
      return v + computeSigma(x+1,y,f)
  }
}

object LetRecInterpreter {
  
  def eval(env: Env, expr: Expr): Val = expr match {
    case Const(n) => IntVal(n)
    case Var(s) =>
      if (env.exists(Var(s)))
        env(Var(s))
      else throw new Exception("1")
    case Add(a, b) => (eval(env, a), eval(env, b)) match {
      case (x: IntVal, y: IntVal) => IntVal(x.n + y.n)
      case _ => throw new Exception("Type Error")
    }
    case Sub(a, b) => (eval(env, a), eval(env, b)) match {
      case (x: IntVal, y: IntVal) => IntVal(x.n - y.n)
      case _ => throw new Exception("Type Error")
    }
    case Iszero(c) => (eval(env, c)) match {
      case (x: IntVal) => BoolVal(x.n == 0)
      case _ => throw new Exception("Type Error")
    }
    case Ite(c, t, f) => eval(env,c) match {
      case v: BoolVal => if (v.b) eval(env,t) else eval(env,f)
      case _ => throw new Exception("Type Error")
    }
    case Let(name, value, body) => eval(env,value) match {
      case x: Val => eval(env.add(name, x), body)
      case _ => throw new Exception("Type Error")
    }
    case Paren(expr: Expr) => eval(env,expr)
    
    case Proc(v, expr) => 
   
      if (env.exists(v)) {
        eval(env, expr)
      } else {
        ProcVal(v, expr, env)
      }
    case PCall(f, arg) => (eval(env,arg), eval(env,f)) match {
      case (x: Val, ProcVal(v, expr2, env2)) => eval(env2.add(v, x), expr2)
      case (x: Val, RecProcVal(f, a, body, expr2, env2)) => eval(env2.add(a, x).add(f, RecProcVal(f, a, body, expr2, env2)), body)
      case _ => throw new Exception("Type Error")
    }
    case LetRec(f, arg, fbody, ibody) => {
      
    eval(env.add(f, RecProcVal(f, arg, fbody, ibody, env)), ibody)
    }     
    
  }

  
  
  def apply(program: String): Val = {
    val parsed = LetRecParserDriver(program)
    eval(Env(new HashMap[Var,Val]()), parsed)
  }

}

object LetRecToString {
  def apply(expr: Expr): String =expr match {
    case Const(n) => s"${n}"
    case Var(s) => s
    case Add(x,y) => s"${apply(x)} + ${apply(y)}"
    case Sub(x,y) => s"${apply(x)} - ${apply(y)}"
    case Iszero(c) => s"iszero ${apply(c)}"
    case Ite(c, t, f) => s"if ${apply(c)} then ${apply(t)} else ${apply(f)}"
    case Let(name, value, body) => s"let ${apply(name)} = ${apply(value)} in ${apply(body)}"
    case Paren(expr) => s"(${apply(expr)})"
    case LetRec(f, arg, fbody, ibody) =>s"letrec ${apply(f)}(${apply(arg)}) = ${apply(fbody)} in ${apply(ibody)}"
    case Proc(v, expr) => s"proc ${apply(v)} ${apply(expr)}"
    case PCall(f, arg) => s"${apply(f)} ${apply(arg)}"
    case _ => throw new Exception("Type Error")    

  }
}

object Hw2App extends App {
  
  println("Hello from Hw2!")

  val int_prog = """x + 1"""
  val parsed = IntParser(int_prog)
}