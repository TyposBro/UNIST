// Generated from /home/azizbek/Desktop/UNIST/principles/hw3/src/main/antlr4/MiniScalaParser.g4 by ANTLR 4.8
package hw3;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MiniScalaParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MiniScalaParserVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(MiniScalaParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr(MiniScalaParser.ExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#iszero}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIszero(MiniScalaParser.IszeroContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#ite}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIte(MiniScalaParser.IteContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#val}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVal(MiniScalaParser.ValContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#var}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar(MiniScalaParser.VarContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProc(MiniScalaParser.ProcContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#def}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDef(MiniScalaParser.DefContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#integer}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInteger(MiniScalaParser.IntegerContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniScalaParser#id}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitId(MiniScalaParser.IdContext ctx);
}