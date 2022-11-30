// Generated from /home/azizbek/Desktop/UNIST/principles/hw4/src/main/antlr4/MiniCParser.g4 by ANTLR 4.8
package hw4;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MiniCParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		WS=1, INT=2, SKIPVAL=3, TRUE=4, FALSE=5, NOT=6, WHILE=7, LET=8, IN=9, 
		PROC=10, PLUS=11, MINUS=12, STAR=13, SLASH=14, EQQ=15, LTE=16, COMMA=17, 
		ASN=18, ISZERO=19, IF=20, THEN=21, ELSE=22, EQ=23, LPAREN=24, RPAREN=25, 
		LANGLE=26, RANGLE=27, LBRACKET=28, RBRACKET=29, DOT=30, BEGIN=31, END=32, 
		SEMI=33, ID=34;
	public static final int
		RULE_program = 0, RULE_expr = 1, RULE_ite = 2, RULE_whileexp = 3, RULE_let = 4, 
		RULE_proc = 5, RULE_records = 6, RULE_record_entry = 7, RULE_not = 8, 
		RULE_skipval = 9, RULE_trueval = 10, RULE_falseval = 11, RULE_integer = 12, 
		RULE_id = 13;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "expr", "ite", "whileexp", "let", "proc", "records", "record_entry", 
			"not", "skipval", "trueval", "falseval", "integer", "id"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, "'skip'", "'true'", "'false'", "'not'", "'while'", 
			"'let'", "'in'", "'proc'", "'+'", "'-'", "'*'", "'/'", "'=='", "'<='", 
			"','", "':='", "'iszero'", "'if'", "'then'", "'else'", "'='", "'('", 
			"')'", "'<'", "'>'", "'{'", "'}'", "'.'", "'begin'", "'end'", "';'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "WS", "INT", "SKIPVAL", "TRUE", "FALSE", "NOT", "WHILE", "LET", 
			"IN", "PROC", "PLUS", "MINUS", "STAR", "SLASH", "EQQ", "LTE", "COMMA", 
			"ASN", "ISZERO", "IF", "THEN", "ELSE", "EQ", "LPAREN", "RPAREN", "LANGLE", 
			"RANGLE", "LBRACKET", "RBRACKET", "DOT", "BEGIN", "END", "SEMI", "ID"
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
	public String getGrammarFileName() { return "MiniCParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MiniCParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode EOF() { return getToken(MiniCParser.EOF, 0); }
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitProgram(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(28);
			expr(0);
			setState(29);
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
		public SkipvalContext skipval() {
			return getRuleContext(SkipvalContext.class,0);
		}
		public TruevalContext trueval() {
			return getRuleContext(TruevalContext.class,0);
		}
		public FalsevalContext falseval() {
			return getRuleContext(FalsevalContext.class,0);
		}
		public IntegerContext integer() {
			return getRuleContext(IntegerContext.class,0);
		}
		public List<IdContext> id() {
			return getRuleContexts(IdContext.class);
		}
		public IdContext id(int i) {
			return getRuleContext(IdContext.class,i);
		}
		public IteContext ite() {
			return getRuleContext(IteContext.class,0);
		}
		public WhileexpContext whileexp() {
			return getRuleContext(WhileexpContext.class,0);
		}
		public LetContext let() {
			return getRuleContext(LetContext.class,0);
		}
		public ProcContext proc() {
			return getRuleContext(ProcContext.class,0);
		}
		public NotContext not() {
			return getRuleContext(NotContext.class,0);
		}
		public TerminalNode ASN() { return getToken(MiniCParser.ASN, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public RecordsContext records() {
			return getRuleContext(RecordsContext.class,0);
		}
		public TerminalNode BEGIN() { return getToken(MiniCParser.BEGIN, 0); }
		public TerminalNode END() { return getToken(MiniCParser.END, 0); }
		public TerminalNode PLUS() { return getToken(MiniCParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(MiniCParser.MINUS, 0); }
		public TerminalNode STAR() { return getToken(MiniCParser.STAR, 0); }
		public TerminalNode SLASH() { return getToken(MiniCParser.SLASH, 0); }
		public TerminalNode LTE() { return getToken(MiniCParser.LTE, 0); }
		public TerminalNode EQQ() { return getToken(MiniCParser.EQQ, 0); }
		public TerminalNode DOT() { return getToken(MiniCParser.DOT, 0); }
		public TerminalNode SEMI() { return getToken(MiniCParser.SEMI, 0); }
		public TerminalNode LPAREN() { return getToken(MiniCParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(MiniCParser.RPAREN, 0); }
		public List<TerminalNode> COMMA() { return getTokens(MiniCParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MiniCParser.COMMA, i);
		}
		public TerminalNode LANGLE() { return getToken(MiniCParser.LANGLE, 0); }
		public TerminalNode RANGLE() { return getToken(MiniCParser.RANGLE, 0); }
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitExpr(this);
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
			setState(51);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				{
				setState(32);
				skipval();
				}
				break;
			case 2:
				{
				setState(33);
				trueval();
				}
				break;
			case 3:
				{
				setState(34);
				falseval();
				}
				break;
			case 4:
				{
				setState(35);
				integer();
				}
				break;
			case 5:
				{
				setState(36);
				id();
				}
				break;
			case 6:
				{
				setState(37);
				ite();
				}
				break;
			case 7:
				{
				setState(38);
				whileexp();
				}
				break;
			case 8:
				{
				setState(39);
				let();
				}
				break;
			case 9:
				{
				setState(40);
				proc();
				}
				break;
			case 10:
				{
				setState(41);
				not();
				}
				break;
			case 11:
				{
				setState(42);
				id();
				setState(43);
				match(ASN);
				setState(44);
				expr(6);
				}
				break;
			case 12:
				{
				setState(46);
				records();
				}
				break;
			case 13:
				{
				setState(47);
				match(BEGIN);
				setState(48);
				expr(0);
				setState(49);
				match(END);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(94);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(92);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(53);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(54);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << PLUS) | (1L << MINUS) | (1L << STAR) | (1L << SLASH) | (1L << EQQ) | (1L << LTE))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(55);
						expr(15);
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(56);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(57);
						match(DOT);
						setState(58);
						id();
						setState(59);
						match(ASN);
						setState(60);
						expr(4);
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(62);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(63);
						match(SEMI);
						setState(64);
						expr(3);
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(65);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(66);
						match(LPAREN);
						setState(67);
						expr(0);
						setState(72);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==COMMA) {
							{
							{
							setState(68);
							match(COMMA);
							setState(69);
							expr(0);
							}
							}
							setState(74);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(75);
						match(RPAREN);
						}
						break;
					case 5:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(77);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(78);
						match(LANGLE);
						setState(79);
						id();
						setState(84);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==COMMA) {
							{
							{
							setState(80);
							match(COMMA);
							setState(81);
							id();
							}
							}
							setState(86);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(87);
						match(RANGLE);
						}
						break;
					case 6:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(89);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(90);
						match(DOT);
						setState(91);
						id();
						}
						break;
					}
					} 
				}
				setState(96);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
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

	public static class IteContext extends ParserRuleContext {
		public TerminalNode IF() { return getToken(MiniCParser.IF, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode THEN() { return getToken(MiniCParser.THEN, 0); }
		public TerminalNode ELSE() { return getToken(MiniCParser.ELSE, 0); }
		public IteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ite; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitIte(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IteContext ite() throws RecognitionException {
		IteContext _localctx = new IteContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_ite);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(97);
			match(IF);
			setState(98);
			expr(0);
			setState(99);
			match(THEN);
			setState(100);
			expr(0);
			setState(101);
			match(ELSE);
			setState(102);
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

	public static class WhileexpContext extends ParserRuleContext {
		public TerminalNode WHILE() { return getToken(MiniCParser.WHILE, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public WhileexpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileexp; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitWhileexp(this);
			else return visitor.visitChildren(this);
		}
	}

	public final WhileexpContext whileexp() throws RecognitionException {
		WhileexpContext _localctx = new WhileexpContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_whileexp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(104);
			match(WHILE);
			setState(105);
			expr(0);
			setState(106);
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

	public static class LetContext extends ParserRuleContext {
		public TerminalNode LET() { return getToken(MiniCParser.LET, 0); }
		public IdContext id() {
			return getRuleContext(IdContext.class,0);
		}
		public TerminalNode EQ() { return getToken(MiniCParser.EQ, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode IN() { return getToken(MiniCParser.IN, 0); }
		public LetContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_let; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitLet(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LetContext let() throws RecognitionException {
		LetContext _localctx = new LetContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_let);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(108);
			match(LET);
			setState(109);
			id();
			setState(110);
			match(EQ);
			setState(111);
			expr(0);
			setState(112);
			match(IN);
			setState(113);
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

	public static class ProcContext extends ParserRuleContext {
		public TerminalNode PROC() { return getToken(MiniCParser.PROC, 0); }
		public TerminalNode LPAREN() { return getToken(MiniCParser.LPAREN, 0); }
		public List<IdContext> id() {
			return getRuleContexts(IdContext.class);
		}
		public IdContext id(int i) {
			return getRuleContext(IdContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(MiniCParser.RPAREN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<TerminalNode> COMMA() { return getTokens(MiniCParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MiniCParser.COMMA, i);
		}
		public ProcContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_proc; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitProc(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProcContext proc() throws RecognitionException {
		ProcContext _localctx = new ProcContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_proc);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			match(PROC);
			setState(116);
			match(LPAREN);
			setState(117);
			id();
			setState(122);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(118);
				match(COMMA);
				setState(119);
				id();
				}
				}
				setState(124);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(125);
			match(RPAREN);
			setState(126);
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

	public static class RecordsContext extends ParserRuleContext {
		public TerminalNode LBRACKET() { return getToken(MiniCParser.LBRACKET, 0); }
		public TerminalNode RBRACKET() { return getToken(MiniCParser.RBRACKET, 0); }
		public List<Record_entryContext> record_entry() {
			return getRuleContexts(Record_entryContext.class);
		}
		public Record_entryContext record_entry(int i) {
			return getRuleContext(Record_entryContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(MiniCParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MiniCParser.COMMA, i);
		}
		public RecordsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_records; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitRecords(this);
			else return visitor.visitChildren(this);
		}
	}

	public final RecordsContext records() throws RecognitionException {
		RecordsContext _localctx = new RecordsContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_records);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(128);
			match(LBRACKET);
			setState(130);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ID) {
				{
				setState(129);
				record_entry();
				}
			}

			setState(136);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(132);
				match(COMMA);
				setState(133);
				record_entry();
				}
				}
				setState(138);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(139);
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

	public static class Record_entryContext extends ParserRuleContext {
		public IdContext id() {
			return getRuleContext(IdContext.class,0);
		}
		public TerminalNode ASN() { return getToken(MiniCParser.ASN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Record_entryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_record_entry; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitRecord_entry(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Record_entryContext record_entry() throws RecognitionException {
		Record_entryContext _localctx = new Record_entryContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_record_entry);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(141);
			id();
			setState(142);
			match(ASN);
			setState(143);
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

	public static class NotContext extends ParserRuleContext {
		public TerminalNode NOT() { return getToken(MiniCParser.NOT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public NotContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_not; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitNot(this);
			else return visitor.visitChildren(this);
		}
	}

	public final NotContext not() throws RecognitionException {
		NotContext _localctx = new NotContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_not);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(145);
			match(NOT);
			setState(146);
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

	public static class SkipvalContext extends ParserRuleContext {
		public TerminalNode SKIPVAL() { return getToken(MiniCParser.SKIPVAL, 0); }
		public SkipvalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_skipval; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitSkipval(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SkipvalContext skipval() throws RecognitionException {
		SkipvalContext _localctx = new SkipvalContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_skipval);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(148);
			match(SKIPVAL);
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

	public static class TruevalContext extends ParserRuleContext {
		public TerminalNode TRUE() { return getToken(MiniCParser.TRUE, 0); }
		public TruevalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_trueval; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitTrueval(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TruevalContext trueval() throws RecognitionException {
		TruevalContext _localctx = new TruevalContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_trueval);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(150);
			match(TRUE);
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

	public static class FalsevalContext extends ParserRuleContext {
		public TerminalNode FALSE() { return getToken(MiniCParser.FALSE, 0); }
		public FalsevalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_falseval; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitFalseval(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FalsevalContext falseval() throws RecognitionException {
		FalsevalContext _localctx = new FalsevalContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_falseval);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(152);
			match(FALSE);
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
		public TerminalNode INT() { return getToken(MiniCParser.INT, 0); }
		public IntegerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integer; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitInteger(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IntegerContext integer() throws RecognitionException {
		IntegerContext _localctx = new IntegerContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_integer);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(154);
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
		public TerminalNode ID() { return getToken(MiniCParser.ID, 0); }
		public IdContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_id; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniCParserVisitor ) return ((MiniCParserVisitor<? extends T>)visitor).visitId(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IdContext id() throws RecognitionException {
		IdContext _localctx = new IdContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_id);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(156);
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
			return precpred(_ctx, 14);
		case 1:
			return precpred(_ctx, 3);
		case 2:
			return precpred(_ctx, 2);
		case 3:
			return precpred(_ctx, 8);
		case 4:
			return precpred(_ctx, 7);
		case 5:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3$\u00a1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3\66"+
		"\n\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\7\3I\n\3\f\3\16\3L\13\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\7\3U\n\3\f\3\16"+
		"\3X\13\3\3\3\3\3\3\3\3\3\3\3\7\3_\n\3\f\3\16\3b\13\3\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7"+
		"\3\7\7\7{\n\7\f\7\16\7~\13\7\3\7\3\7\3\7\3\b\3\b\5\b\u0085\n\b\3\b\3\b"+
		"\7\b\u0089\n\b\f\b\16\b\u008c\13\b\3\b\3\b\3\t\3\t\3\t\3\t\3\n\3\n\3\n"+
		"\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\17\2\3\4\20\2\4\6\b\n"+
		"\f\16\20\22\24\26\30\32\34\2\3\3\2\r\22\2\u00a9\2\36\3\2\2\2\4\65\3\2"+
		"\2\2\6c\3\2\2\2\bj\3\2\2\2\nn\3\2\2\2\fu\3\2\2\2\16\u0082\3\2\2\2\20\u008f"+
		"\3\2\2\2\22\u0093\3\2\2\2\24\u0096\3\2\2\2\26\u0098\3\2\2\2\30\u009a\3"+
		"\2\2\2\32\u009c\3\2\2\2\34\u009e\3\2\2\2\36\37\5\4\3\2\37 \7\2\2\3 \3"+
		"\3\2\2\2!\"\b\3\1\2\"\66\5\24\13\2#\66\5\26\f\2$\66\5\30\r\2%\66\5\32"+
		"\16\2&\66\5\34\17\2\'\66\5\6\4\2(\66\5\b\5\2)\66\5\n\6\2*\66\5\f\7\2+"+
		"\66\5\22\n\2,-\5\34\17\2-.\7\24\2\2./\5\4\3\b/\66\3\2\2\2\60\66\5\16\b"+
		"\2\61\62\7!\2\2\62\63\5\4\3\2\63\64\7\"\2\2\64\66\3\2\2\2\65!\3\2\2\2"+
		"\65#\3\2\2\2\65$\3\2\2\2\65%\3\2\2\2\65&\3\2\2\2\65\'\3\2\2\2\65(\3\2"+
		"\2\2\65)\3\2\2\2\65*\3\2\2\2\65+\3\2\2\2\65,\3\2\2\2\65\60\3\2\2\2\65"+
		"\61\3\2\2\2\66`\3\2\2\2\678\f\20\2\289\t\2\2\29_\5\4\3\21:;\f\5\2\2;<"+
		"\7 \2\2<=\5\34\17\2=>\7\24\2\2>?\5\4\3\6?_\3\2\2\2@A\f\4\2\2AB\7#\2\2"+
		"B_\5\4\3\5CD\f\n\2\2DE\7\32\2\2EJ\5\4\3\2FG\7\23\2\2GI\5\4\3\2HF\3\2\2"+
		"\2IL\3\2\2\2JH\3\2\2\2JK\3\2\2\2KM\3\2\2\2LJ\3\2\2\2MN\7\33\2\2N_\3\2"+
		"\2\2OP\f\t\2\2PQ\7\34\2\2QV\5\34\17\2RS\7\23\2\2SU\5\34\17\2TR\3\2\2\2"+
		"UX\3\2\2\2VT\3\2\2\2VW\3\2\2\2WY\3\2\2\2XV\3\2\2\2YZ\7\35\2\2Z_\3\2\2"+
		"\2[\\\f\6\2\2\\]\7 \2\2]_\5\34\17\2^\67\3\2\2\2^:\3\2\2\2^@\3\2\2\2^C"+
		"\3\2\2\2^O\3\2\2\2^[\3\2\2\2_b\3\2\2\2`^\3\2\2\2`a\3\2\2\2a\5\3\2\2\2"+
		"b`\3\2\2\2cd\7\26\2\2de\5\4\3\2ef\7\27\2\2fg\5\4\3\2gh\7\30\2\2hi\5\4"+
		"\3\2i\7\3\2\2\2jk\7\t\2\2kl\5\4\3\2lm\5\4\3\2m\t\3\2\2\2no\7\n\2\2op\5"+
		"\34\17\2pq\7\31\2\2qr\5\4\3\2rs\7\13\2\2st\5\4\3\2t\13\3\2\2\2uv\7\f\2"+
		"\2vw\7\32\2\2w|\5\34\17\2xy\7\23\2\2y{\5\34\17\2zx\3\2\2\2{~\3\2\2\2|"+
		"z\3\2\2\2|}\3\2\2\2}\177\3\2\2\2~|\3\2\2\2\177\u0080\7\33\2\2\u0080\u0081"+
		"\5\4\3\2\u0081\r\3\2\2\2\u0082\u0084\7\36\2\2\u0083\u0085\5\20\t\2\u0084"+
		"\u0083\3\2\2\2\u0084\u0085\3\2\2\2\u0085\u008a\3\2\2\2\u0086\u0087\7\23"+
		"\2\2\u0087\u0089\5\20\t\2\u0088\u0086\3\2\2\2\u0089\u008c\3\2\2\2\u008a"+
		"\u0088\3\2\2\2\u008a\u008b\3\2\2\2\u008b\u008d\3\2\2\2\u008c\u008a\3\2"+
		"\2\2\u008d\u008e\7\37\2\2\u008e\17\3\2\2\2\u008f\u0090\5\34\17\2\u0090"+
		"\u0091\7\24\2\2\u0091\u0092\5\4\3\2\u0092\21\3\2\2\2\u0093\u0094\7\b\2"+
		"\2\u0094\u0095\5\4\3\2\u0095\23\3\2\2\2\u0096\u0097\7\5\2\2\u0097\25\3"+
		"\2\2\2\u0098\u0099\7\6\2\2\u0099\27\3\2\2\2\u009a\u009b\7\7\2\2\u009b"+
		"\31\3\2\2\2\u009c\u009d\7\4\2\2\u009d\33\3\2\2\2\u009e\u009f\7$\2\2\u009f"+
		"\35\3\2\2\2\n\65JV^`|\u0084\u008a";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}