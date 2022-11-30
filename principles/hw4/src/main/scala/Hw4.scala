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
      case None => None
    }
  }
  def get(l: LocVal): Option[Val] = m.get(l)
  def getLocs(): List[LocVal] = m.keySet.toList
}

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
  override def toString = s"Var(${"\""}${s}${"\""})"
}
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
    
  
  def eval(env: Env, mem: Mem, expr: Expr): Result = expr match {
    case Skip => Result(SkipVal, mem);
    case False => Result(BoolVal(false), mem)
    case True => Result(BoolVal(true), mem)
    case Const(n: Int) => Result(IntVal(n), mem)
    case NotExpr(expr: Expr) => {
      val x = eval(env, mem, expr)
      x.v match {
        case BoolVal(b: Boolean) => Result(BoolVal(!b), x.m)
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }

    

    case Var(s: String) => {
      val x = if(env.exists((e: (Var, Val)) => e._1 == Var(s))) env(Var(s)) else throw new UndefinedSemantics(s"Variable ${s} does not exist")
      x match{
        case LocVal(l: Int) => mem.get(x) match{
          case Some(v) => Result(v, mem)
          case None => throw UndefinedSemantics(s"Error!")
        }
        case _ => Result(x, mem)
      }
    }

    case Add(l,r) =>  {
      val a = eval(env, mem, l)
      val b = eval(env, a.m, r)
      (a, b) match{ 
        case (Result(IntVal(x), xmem: Mem), Result(IntVal(y), ymem: Mem)) => Result(IntVal(x + y), b.m)
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }

    case Sub(l,r) =>  {
      val a = eval(env, mem, l)
      val b = eval(env, a.m, r)
      (a, b) match{ 
        case (Result(IntVal(x), xmem: Mem), Result(IntVal(y), ymem: Mem)) => Result(IntVal(x - y), b.m)
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }

    case Mul(l,r) =>  {
      val a = eval(env, mem, l)
      val b = eval(env, a.m, r)
      (a, b) match{ 
        case (Result(IntVal(x), xmem: Mem), Result(IntVal(y), ymem: Mem)) => Result(IntVal(x * y), b.m)
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }
    case Div(l,r) =>  {
      val a = eval(env, mem, l)
      val b = eval(env, a.m, r)
      (a, b) match{ 
        case (Result(IntVal(x), xmem: Mem), Result(IntVal(y), ymem: Mem)) => if(y != 0) Result(IntVal(x / y), b.m) else throw new UndefinedSemantics("dont divide by zero")
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }


    case LTEExpr(l, r) => {
      val a = eval(env, mem, l)
      val b = eval(env, a.m, r)

      (a, b) match {
        case (Result(IntVal(x), xmem: Mem), Result(IntVal(y), ymem: Mem)) => Result(BoolVal(x <= y), b.m)
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }

    case EQExpr(l, r) => {
      val a = eval(env, mem, l)
      val b = eval(env, a.m, r)

      (a, b) match {
        case (Result(IntVal(x), xmem: Mem), Result(IntVal(y), ymem: Mem)) => Result(BoolVal(x == y), b.m)
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }

    case Iszero(c) => {
      val a = eval(env, mem, c)

      a match {
        case Result(IntVal(n), xmem: Mem) => Result(BoolVal(n == 0), xmem)
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }

    case Ite(c, t, f) => {
      val x = eval(env, mem, c)
      x match {
        case Result(BoolVal(b: Boolean), xmem: Mem) => if (b) eval(env, xmem, t) else eval(env, xmem, f)
        case _ => throw new UndefinedSemantics(s"Error!")
      }
    }
    case Let(n, value, body) =>  {
      val x = eval(env, mem, value)
      x.v match{
      case j: Val => {
        val y = x.m.extended(x.v)
        val nenv = env + (n -> y._2)
        eval(nenv, y._1, body)
      }
      case _ => throw new UndefinedSemantics(s"Error")
    }}
    case Proc(v, expr) => Result(ProcVal(v, expr, env), mem)

    case Asn(v: Var, e: Expr) => {
      val x = eval(env, mem, e)
      if(env.exists((e: (Var, Val)) => e._1 == v)){
        val y = x.m.updated(env(v), x.v)
        y match{
          case Some(z) => Result(x.v, z)
          case None => throw new UndefinedSemantics(s"Error!")
        }
      }
      else throw new UndefinedSemantics(s"Error!")
    }
    case BeginEnd(expr) => eval(env, mem, expr)
    case FieldAccess(record, field) => {
      val x = eval(env, mem, record)
      x.v match {
        case RecordVal(v: Var, l: LocVal, n: RecordValLike) => {
          def getVal(r: RecordVal, v: Var): LocVal = if(r.field == v) r.loc else{
            n match{
              case EmptyRecordVal => throw new UndefinedSemantics(s"Error!")
              case k: RecordVal => getVal(k, v)
            }
          }
          val y = getVal(x.v.asInstanceOf[RecordVal], field)
          x.m.get(y) match{
            case Some(z) => Result(z, x.m)
            case None => throw UndefinedSemantics(s"Error!")
          }
        }
        case _ => throw new UndefinedSemantics(s"Type Error!")
      }
    }
    case FieldAssign(record: Expr, field: Var, new_val: Expr) => {
      val x = eval(env, mem, record)
      val y = eval(env, x.m, new_val)
      def getVal(r: RecordVal, v: Var): LocVal = if(r.field == v) r.loc else{
        x.v.asInstanceOf[RecordVal].next match{
          case EmptyRecordVal => throw new UndefinedSemantics(s"Field Error!")
          case k: RecordVal => getVal(k, v)
        }
      }
      val z = getVal(x.v.asInstanceOf[RecordVal], field)
      val q = y.m.updated(z, y.v)
      q match{
        case Some(t) => Result(y.v, t)
        case None => throw new UndefinedSemantics(s"Error!")
      }
    }
    case  Block(f: Expr, s: Expr) => {
      val first = eval(env, mem, f)
      eval(env, first.m, s)
    }
    case PCallV(ftn: Expr, arg: List[Expr]) => {
      val f = eval(env, mem, ftn)
      f.v match{
        case ProcVal(par: List[Var], body: Expr, en: Env) =>{
          if(arg.length != par.length) throw new UndefinedSemantics(s"Error!")
          else{
            def evalArg(a: List[Expr], p: List[Var], m: Mem, e: Env): (Mem, Env) = {
            if(a.isEmpty) (m, e)
            else{
              val x = eval(env, m, a(0))
              val y = x.m.extended(x.v)
              val z: Env = e + (p(0) -> y._2)
              evalArg(a.drop(1), p.drop(1), y._1, z)
            }
          } 
          val nme = evalArg(arg, par, f.m, en)
          eval(nme._2, nme._1, body)
          }
        }
        case _ => throw new UndefinedSemantics(s"Proc Error!") 
      }
    }
    case PCallR(ftn: Expr, arg: List[Var]) => {
      val f = eval(env, mem, ftn)
      f.v match{
        case ProcVal(par: List[Var], body: Expr, en: Env) => {
          if(arg.length != par.length) throw new UndefinedSemantics(s"Error!")
          else{
            def getVal(a: List[Var], p: List[Var], e: Env): Env = {
              if(a.isEmpty) e else{
                if(env.exists((t: (Var, Val)) => t._1 == a(0))) getVal(a.drop(1), p.drop(1), e + (p(0) -> env(a(0))))
                else throw new UndefinedSemantics(s"Unknown variable!") 
              }
            }
            eval(getVal(arg, par, en), f.m, body) 
          }
        }
        case _ => throw new UndefinedSemantics(s"Not a Proc")
      }
    }
    case WhileExpr(cond: Expr, body: Expr) => {
      val x = eval(env, mem, cond)
      x.v match {
        case b: BoolVal => if(b.b) {
            val y = eval(env, x.m, body)
            eval(env, y.m, expr)
          }else Result(SkipVal, x.m)
        case _ => throw new UndefinedSemantics(s"Not Boolean")
      }
    }
    case EmptyRecordExpr => Result(EmptyRecordVal, mem)
    case RecordExpr(field: Var, initVal: Expr, next: RecordLike) => {
      val x = eval(env, mem, initVal)
      val y = x.m.extended(x.v)
      val z = eval(env, y._1, next)
      Result(RecordVal(field, y._2, z.v.asInstanceOf[RecordValLike]), z.m)
    }
  }

  def gc(env: Env, mem: Mem): Mem = {
    Mem(mem.m, mem.top)
  }
  
  def apply(program: String): (Val, Mem) = {
    val parsed = MiniCParserDriver(program)
    val res = eval(new Env(), Mem(new HashMap[LocVal,Val],0), parsed)
    (res.v, res.m)
  }

}


object Hw4App extends App {
  
  println("Hello from Hw4!")

}