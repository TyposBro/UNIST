package Hw2

import org.antlr.v4.runtime._
import org.antlr.v4.runtime.tree.{TerminalNode}

import fastparse._
import MultiLineWhitespace._
import scala.collection.immutable.HashMap 
import scala.collection.JavaConverters._

class LetRecVisitor extends LetRecParserBaseVisitor[Expr] {
  override def visitInteger(ctx: LetRecParser.IntegerContext): Const = {
    val exprText = ctx.getText
    Const(exprText.toInt)
  }
  override def visitId(ctx: LetRecParser.IdContext): Var = {
    val exprText = ctx.getText
    Var(exprText)
  }

  

  override def visitExpr(ctx: LetRecParser.ExprContext): Expr = {
    
    ctx.getChild(0).toString match {
      case "iszero" => Iszero(visit(ctx.getChild(1)))
      case "if" => Ite(visit(ctx.expr(0)), visit(ctx.expr(1)), visit(ctx.expr(2)))
      case "let" => Let(visitId(ctx.id(0)), visit(ctx.expr(0)), visit(ctx.expr(1)))
      case "letrec" => LetRec(visitId(ctx.id(0)),visitId(ctx.id(1)), visit(ctx.expr(0)), visit(ctx.expr(1)))
      case "proc" => Proc(visitId(ctx.id(0)), visitExpr(ctx.expr(0)))
      case "(" => Paren(visit(ctx.expr(0)))
      case _ => 
        ctx.getChildCount match {
          case 1 => visit(ctx.getChild(0))
          case 2 => PCall(visit(ctx.expr(0)),visit(ctx.expr(1)))
          case 3 => 
            ctx.getChild(1).toString match {
            case "+" => Add(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "-" => Sub(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case unknown => throw new Exception(s"unknown token: ${unknown}")
          }
        }
    }
  }
} // LetRecVisitor

object LetRecParserDriver {
  
  

  def apply(program: String): Expr = {
    val charStream  = new ANTLRInputStream(program)
    val lexer       = new LetRecLexer(charStream)
    val tokens      = new CommonTokenStream(lexer)
  
    val parser      = new LetRecParser(tokens)
    
    val visitor     = new LetRecVisitor()
    val res         = visitor.visit(parser.expr())

    val r = res.asInstanceOf[Expr]
    r
  }
}

class IntVisitor extends IntParserAntlr4BaseVisitor[IntExpr] {
  override def visitInteger(ctx: IntParserAntlr4.IntegerContext): IntConst = {
    val exprText = ctx.getText
    IntConst(exprText.toInt)
  }
  override def visitId(ctx: IntParserAntlr4.IdContext): IntExpr =  {
    println(ctx.getText)
    IntVar
  }


  

  override def visitExpr(ctx: IntParserAntlr4.ExprContext): IntExpr = {
    
    //println(ctx.getText)
    ctx.getChild(0).toString match {
      case "sigma" => IntSigma(visit(ctx.expr(0)), visit(ctx.expr(1)), visit(ctx.expr(2)))
      case "pow" => IntPow(visit(ctx.expr(0)), visit(ctx.expr(1)))
      case _ => 
        ctx.getChildCount match {
          case 1 => visit(ctx.getChild(0))
          case 3 => 
            ctx.getChild(1).toString match {
            case "+" => IntAdd(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "-" => IntSub(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "*" => IntMul(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case unknown => throw new Exception(s"unknown token: ${unknown}")
          }
        }
    }
  }
} // IntVisitor

object IntParser {

  def apply(program: String): IntExpr = {
    val charStream  = new ANTLRInputStream(program)
  
    val lexer       = new IntLexer(charStream)
    val tokens      = new CommonTokenStream(lexer)
    
    val parser      = new IntParserAntlr4(tokens)
    
    val visitor     = new IntVisitor()
    val res         = visitor.visit(parser.expr())

    val r = res.asInstanceOf[IntExpr]
    println(r)
    r
  }
}