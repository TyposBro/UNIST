package hw4

import org.antlr.v4.runtime._
import org.antlr.v4.runtime.tree.{TerminalNode}
import MiniCParser._

import scala.collection.immutable.HashMap 
import scala.collection.JavaConverters._

case class SyntaxError (msg: String = "", cause: Throwable = None.orNull) extends Exception("Syntax Error: " ++ msg, cause)

class MiniCVisitor extends MiniCParserBaseVisitor[Expr] {

  override def visitSkipval(ctx: SkipvalContext): Expr = {
    Skip
  }
  override def visitTrueval(ctx: TruevalContext): Expr = {
    True
  }
  override def visitFalseval(ctx: FalsevalContext): Expr = {
    False
  }
  override def visitNot(ctx: NotContext): NotExpr = {
    NotExpr(visit(ctx.expr()))
  }
  override def visitInteger(ctx: IntegerContext): Const = {
    val exprText = ctx.getText
    Const(exprText.toInt)
  }
  override def visitId(ctx: IdContext): Var = {
    val exprText = ctx.getText
    Var(exprText)
  }

  override def visitIte(ctx: IteContext): Ite = 
    Ite(visit(ctx.expr(0)), visit(ctx.expr(1)), visit(ctx.expr(2)))
  
  override def visitProc(ctx: ProcContext): Proc = 
    Proc(ctx.id().asScala.toList.map(visitId(_)), visit(ctx.expr()))

  override def visitLet(ctx: LetContext): Let = 
    Let(visitId(ctx.id()), visit(ctx.expr(0)), visit(ctx.expr(1)))
  
  def recordEntryToRecordExpr(entries: List[Record_entryContext]): RecordLike = 
    entries match {
      case Nil => EmptyRecordExpr
      case _ => {
        RecordExpr(visitId(entries(0).id()), visitExpr(entries(0).expr), recordEntryToRecordExpr(entries.drop(1)))
      }
    }
  override def visitRecords(ctx: RecordsContext): RecordLike = 
    recordEntryToRecordExpr(ctx.record_entry().asScala.toList)
    
  
  override def visitWhileexp(ctx: WhileexpContext): WhileExpr = 
    WhileExpr(visit(ctx.expr(0)), visit(ctx.expr(1)))
  override def visitExpr(ctx: ExprContext): Expr = {
    ctx.getChildCount match {
      case 1 => visit(ctx.getChild(0))
      case 3 => (ctx.getChild(0).toString,ctx.getChild(2).toString) match {
        case ("begin","end") => BeginEnd(visit(ctx.expr(0)))
        case _ => {
            ctx.getChild(1).toString match {
            case "+" => Add(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "-" => Sub(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "*" => Mul(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "/" => Div(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "<=" => LTEExpr(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "==" => EQExpr(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case ":=" => Asn(visitId(ctx.id(0)), visitExpr(ctx.expr(0)))
            case ";" => Block(visit(ctx.getChild(0)), visit(ctx.getChild(2)))
            case "." => FieldAccess(visit(ctx.getChild(0)), visitId(ctx.id(0)))
            case unknown => throw new SyntaxError(s"unknown token on binary op: ${unknown} @ ${ctx.getText()}")
          }
        }
      }
      case 5 if (ctx.getChild(1).toString == "." && ctx.getChild(3).toString == ":=") => {
        FieldAssign(visit(ctx.getChild(0)),visitId(ctx.id(0)),visit(ctx.getChild(4)))
      }
      case _ => {
        val count = ctx.getChildCount()
        (ctx.getChild(1).toString, ctx.getChild(count-1).toString) match {
          case ("(", ")") => PCallV(visit(ctx.getChild(0)), ctx.expr().asScala.toList.drop(1).map(visit(_)))
          case ("<", ">") => PCallR(visit(ctx.getChild(0)), ctx.id().asScala.toList.map(visitId(_)))
          case _ => throw new SyntaxError(ctx.getText())
        }
      }
      
    }
  }

  override def visitProgram(ctx: ProgramContext): Expr = {
    visit(ctx.expr())
  }
}

object MiniCParserDriver {
  

  def apply(program: String): Expr = {
    val charStream  = new ANTLRInputStream(program)
    val lexer       = new MiniCLexer(charStream)
    val tokens      = new CommonTokenStream(lexer)
  
    val parser      = new MiniCParser(tokens)
    
    val tree = parser.program()
    val numErrors = parser.getNumberOfSyntaxErrors()
    parser.reset()
    val visitor     = new MiniCVisitor()
    val res         = visitor.visit(parser.program())

    
    if (numErrors != 0) {
      val msg = "found " ++ numErrors.toString ++ " Errors"
      throw new SyntaxError(msg)
    }
    val r = res.asInstanceOf[Expr]
    r
  }
}
