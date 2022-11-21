// Generated from /home/azizbek/Desktop/UNIST/principles/hw3/src/main/antlr4/MiniScalaParser.g4 by ANTLR 4.8
package hw3;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MiniScalaParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		WS=1, INT=2, VAR=3, VAL=4, DEF=5, PLUS=6, MINUS=7, STAR=8, SLASH=9, SEMI=10, 
		ARROW=11, GT=12, GEQ=13, ASN=14, ISZERO=15, IF=16, THEN=17, ELSE=18, EQ=19, 
		LPAREN=20, RPAREN=21, LBRACKET=22, RBRACKET=23, ID=24;
	public static final int
		RULE_program = 0, RULE_expr = 1, RULE_iszero = 2, RULE_ite = 3, RULE_val = 4, 
		RULE_var = 5, RULE_proc = 6, RULE_def = 7, RULE_integer = 8, RULE_id = 9;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "expr", "iszero", "ite", "val", "var", "proc", "def", "integer", 
			"id"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, "'var'", "'val'", "'def'", "'+'", "'-'", "'*'", "'/'", 
			"';'", "'=>'", "'>'", "'>='", "':='", "'iszero'", "'if'", "'then'", "'else'", 
			"'='", "'('", "')'", "'{'", "'}'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "WS", "INT", "VAR", "VAL", "DEF", "PLUS", "MINUS", "STAR", "SLASH", 
			"SEMI", "ARROW", "GT", "GEQ", "ASN", "ISZERO", "IF", "THEN", "ELSE", 
			"EQ", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "ID"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "MiniScalaParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MiniScalaParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode EOF() { return getToken(MiniScalaParser.EOF, 0); }
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitProgram(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(20);
			expr(0);
			setState(21);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public IntegerContext integer() {
			return getRuleContext(IntegerContext.class,0);
		}
		public IdContext id() {
			return getRuleContext(IdContext.class,0);
		}
		public IszeroContext iszero() {
			return getRuleContext(IszeroContext.class,0);
		}
		public IteContext ite() {
			return getRuleContext(IteContext.class,0);
		}
		public ValContext val() {
			return getRuleContext(ValContext.class,0);
		}
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public ProcContext proc() {
			return getRuleContext(ProcContext.class,0);
		}
		public DefContext def() {
			return getRuleContext(DefContext.class,0);
		}
		public TerminalNode ASN() { return getToken(MiniScalaParser.ASN, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode LPAREN() { return getToken(MiniScalaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(MiniScalaParser.RPAREN, 0); }
		public TerminalNode LBRACKET() { return getToken(MiniScalaParser.LBRACKET, 0); }
		public TerminalNode RBRACKET() { return getToken(MiniScalaParser.RBRACKET, 0); }
		public TerminalNode PLUS() { return getToken(MiniScalaParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(MiniScalaParser.MINUS, 0); }
		public TerminalNode STAR() { return getToken(MiniScalaParser.STAR, 0); }
		public TerminalNode SLASH() { return getToken(MiniScalaParser.SLASH, 0); }
		public TerminalNode GT() { return getToken(MiniScalaParser.GT, 0); }
		public TerminalNode GEQ() { return getToken(MiniScalaParser.GEQ, 0); }
		public TerminalNode SEMI() { return getToken(MiniScalaParser.SEMI, 0); }
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitExpr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				{
				setState(24);
				integer();
				}
				break;
			case 2:
				{
				setState(25);
				id();
				}
				break;
			case 3:
				{
				setState(26);
				iszero();
				}
				break;
			case 4:
				{
				setState(27);
				ite();
				}
				break;
			case 5:
				{
				setState(28);
				val();
				}
				break;
			case 6:
				{
				setState(29);
				var();
				}
				break;
			case 7:
				{
				setState(30);
				proc();
				}
				break;
			case 8:
				{
				setState(31);
				def();
				}
				break;
			case 9:
				{
				setState(32);
				id();
				setState(33);
				match(ASN);
				setState(34);
				expr(5);
				}
				break;
			case 10:
				{
				setState(36);
				match(LPAREN);
				setState(37);
				expr(0);
				setState(38);
				match(RPAREN);
				}
				break;
			case 11:
				{
				setState(40);
				match(LBRACKET);
				setState(41);
				expr(0);
				setState(42);
				match(RBRACKET);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(56);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(54);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(46);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(47);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << PLUS) | (1L << MINUS) | (1L << STAR) | (1L << SLASH) | (1L << GT) | (1L << GEQ))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(48);
						expr(13);
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(49);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(50);
						match(SEMI);
						setState(51);
						expr(5);
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(52);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(53);
						expr(4);
						}
						break;
					}
					} 
				}
				setState(58);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class IszeroContext extends ParserRuleContext {
		public TerminalNode ISZERO() { return getToken(MiniScalaParser.ISZERO, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public IszeroContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_iszero; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitIszero(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IszeroContext iszero() throws RecognitionException {
		IszeroContext _localctx = new IszeroContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_iszero);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			match(ISZERO);
			setState(60);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IteContext extends ParserRuleContext {
		public TerminalNode IF() { return getToken(MiniScalaParser.IF, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode THEN() { return getToken(MiniScalaParser.THEN, 0); }
		public TerminalNode ELSE() { return getToken(MiniScalaParser.ELSE, 0); }
		public IteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ite; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitIte(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IteContext ite() throws RecognitionException {
		IteContext _localctx = new IteContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_ite);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			match(IF);
			setState(63);
			expr(0);
			setState(64);
			match(THEN);
			setState(65);
			expr(0);
			setState(66);
			match(ELSE);
			setState(67);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ValContext extends ParserRuleContext {
		public TerminalNode LBRACKET() { return getToken(MiniScalaParser.LBRACKET, 0); }
		public TerminalNode VAL() { return getToken(MiniScalaParser.VAL, 0); }
		public IdContext id() {
			return getRuleContext(IdContext.class,0);
		}
		public TerminalNode EQ() { return getToken(MiniScalaParser.EQ, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(MiniScalaParser.SEMI, 0); }
		public TerminalNode RBRACKET() { return getToken(MiniScalaParser.RBRACKET, 0); }
		public ValContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_val; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitVal(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ValContext val() throws RecognitionException {
		ValContext _localctx = new ValContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_val);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			match(LBRACKET);
			setState(70);
			match(VAL);
			setState(71);
			id();
			setState(72);
			match(EQ);
			setState(73);
			expr(0);
			setState(74);
			match(SEMI);
			setState(75);
			expr(0);
			setState(76);
			match(RBRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarContext extends ParserRuleContext {
		public TerminalNode LBRACKET() { return getToken(MiniScalaParser.LBRACKET, 0); }
		public TerminalNode VAR() { return getToken(MiniScalaParser.VAR, 0); }
		public IdContext id() {
			return getRuleContext(IdContext.class,0);
		}
		public TerminalNode EQ() { return getToken(MiniScalaParser.EQ, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(MiniScalaParser.SEMI, 0); }
		public TerminalNode RBRACKET() { return getToken(MiniScalaParser.RBRACKET, 0); }
		public VarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitVar(this);
			else return visitor.visitChildren(this);
		}
	}

	public final VarContext var() throws RecognitionException {
		VarContext _localctx = new VarContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_var);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(78);
			match(LBRACKET);
			setState(79);
			match(VAR);
			setState(80);
			id();
			setState(81);
			match(EQ);
			setState(82);
			expr(0);
			setState(83);
			match(SEMI);
			setState(84);
			expr(0);
			setState(85);
			match(RBRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(MiniScalaParser.LPAREN, 0); }
		public IdContext id() {
			return getRuleContext(IdContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(MiniScalaParser.RPAREN, 0); }
		public TerminalNode ARROW() { return getToken(MiniScalaParser.ARROW, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ProcContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_proc; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitProc(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProcContext proc() throws RecognitionException {
		ProcContext _localctx = new ProcContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_proc);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(87);
			match(LPAREN);
			setState(88);
			id();
			setState(89);
			match(RPAREN);
			setState(90);
			match(ARROW);
			setState(91);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DefContext extends ParserRuleContext {
		public TerminalNode LBRACKET() { return getToken(MiniScalaParser.LBRACKET, 0); }
		public TerminalNode DEF() { return getToken(MiniScalaParser.DEF, 0); }
		public List<IdContext> id() {
			return getRuleContexts(IdContext.class);
		}
		public IdContext id(int i) {
			return getRuleContext(IdContext.class,i);
		}
		public TerminalNode LPAREN() { return getToken(MiniScalaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(MiniScalaParser.RPAREN, 0); }
		public TerminalNode EQ() { return getToken(MiniScalaParser.EQ, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(MiniScalaParser.SEMI, 0); }
		public TerminalNode RBRACKET() { return getToken(MiniScalaParser.RBRACKET, 0); }
		public DefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_def; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitDef(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DefContext def() throws RecognitionException {
		DefContext _localctx = new DefContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_def);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			match(LBRACKET);
			setState(94);
			match(DEF);
			setState(95);
			id();
			setState(96);
			match(LPAREN);
			setState(97);
			id();
			setState(98);
			match(RPAREN);
			setState(99);
			match(EQ);
			setState(100);
			expr(0);
			setState(101);
			match(SEMI);
			setState(102);
			expr(0);
			setState(103);
			match(RBRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IntegerContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(MiniScalaParser.INT, 0); }
		public IntegerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integer; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitInteger(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IntegerContext integer() throws RecognitionException {
		IntegerContext _localctx = new IntegerContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_integer);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(105);
			match(INT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MiniScalaParser.ID, 0); }
		public IdContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_id; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniScalaParserVisitor ) return ((MiniScalaParserVisitor<? extends T>)visitor).visitId(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IdContext id() throws RecognitionException {
		IdContext _localctx = new IdContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_id);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(107);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 12);
		case 1:
			return precpred(_ctx, 4);
		case 2:
			return precpred(_ctx, 3);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\32p\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\3"+
		"\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\5\3/\n\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\7\3"+
		"9\n\3\f\3\16\3<\13\3\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\3"+
		"\n\3\13\3\13\3\13\2\3\4\f\2\4\6\b\n\f\16\20\22\24\2\3\4\2\b\13\16\17\2"+
		"r\2\26\3\2\2\2\4.\3\2\2\2\6=\3\2\2\2\b@\3\2\2\2\nG\3\2\2\2\fP\3\2\2\2"+
		"\16Y\3\2\2\2\20_\3\2\2\2\22k\3\2\2\2\24m\3\2\2\2\26\27\5\4\3\2\27\30\7"+
		"\2\2\3\30\3\3\2\2\2\31\32\b\3\1\2\32/\5\22\n\2\33/\5\24\13\2\34/\5\6\4"+
		"\2\35/\5\b\5\2\36/\5\n\6\2\37/\5\f\7\2 /\5\16\b\2!/\5\20\t\2\"#\5\24\13"+
		"\2#$\7\20\2\2$%\5\4\3\7%/\3\2\2\2&\'\7\26\2\2\'(\5\4\3\2()\7\27\2\2)/"+
		"\3\2\2\2*+\7\30\2\2+,\5\4\3\2,-\7\31\2\2-/\3\2\2\2.\31\3\2\2\2.\33\3\2"+
		"\2\2.\34\3\2\2\2.\35\3\2\2\2.\36\3\2\2\2.\37\3\2\2\2. \3\2\2\2.!\3\2\2"+
		"\2.\"\3\2\2\2.&\3\2\2\2.*\3\2\2\2/:\3\2\2\2\60\61\f\16\2\2\61\62\t\2\2"+
		"\2\629\5\4\3\17\63\64\f\6\2\2\64\65\7\f\2\2\659\5\4\3\7\66\67\f\5\2\2"+
		"\679\5\4\3\68\60\3\2\2\28\63\3\2\2\28\66\3\2\2\29<\3\2\2\2:8\3\2\2\2:"+
		";\3\2\2\2;\5\3\2\2\2<:\3\2\2\2=>\7\21\2\2>?\5\4\3\2?\7\3\2\2\2@A\7\22"+
		"\2\2AB\5\4\3\2BC\7\23\2\2CD\5\4\3\2DE\7\24\2\2EF\5\4\3\2F\t\3\2\2\2GH"+
		"\7\30\2\2HI\7\6\2\2IJ\5\24\13\2JK\7\25\2\2KL\5\4\3\2LM\7\f\2\2MN\5\4\3"+
		"\2NO\7\31\2\2O\13\3\2\2\2PQ\7\30\2\2QR\7\5\2\2RS\5\24\13\2ST\7\25\2\2"+
		"TU\5\4\3\2UV\7\f\2\2VW\5\4\3\2WX\7\31\2\2X\r\3\2\2\2YZ\7\26\2\2Z[\5\24"+
		"\13\2[\\\7\27\2\2\\]\7\r\2\2]^\5\4\3\2^\17\3\2\2\2_`\7\30\2\2`a\7\7\2"+
		"\2ab\5\24\13\2bc\7\26\2\2cd\5\24\13\2de\7\27\2\2ef\7\25\2\2fg\5\4\3\2"+
		"gh\7\f\2\2hi\5\4\3\2ij\7\31\2\2j\21\3\2\2\2kl\7\4\2\2l\23\3\2\2\2mn\7"+
		"\32\2\2n\25\3\2\2\2\5.8:";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}