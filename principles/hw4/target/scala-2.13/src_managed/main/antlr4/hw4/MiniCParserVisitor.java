// Generated from /home/azizbek/Desktop/UNIST/principles/hw4/src/main/antlr4/MiniCParser.g4 by ANTLR 4.8
package hw4;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MiniCParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MiniCParserVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MiniCParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(MiniCParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr(MiniCParser.ExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#ite}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIte(MiniCParser.IteContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#whileexp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitWhileexp(MiniCParser.WhileexpContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#let}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLet(MiniCParser.LetContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProc(MiniCParser.ProcContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#records}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecords(MiniCParser.RecordsContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#record_entry}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecord_entry(MiniCParser.Record_entryContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#not}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNot(MiniCParser.NotContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#skipval}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSkipval(MiniCParser.SkipvalContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#trueval}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTrueval(MiniCParser.TruevalContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#falseval}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFalseval(MiniCParser.FalsevalContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#integer}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInteger(MiniCParser.IntegerContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#id}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitId(MiniCParser.IdContext ctx);
}