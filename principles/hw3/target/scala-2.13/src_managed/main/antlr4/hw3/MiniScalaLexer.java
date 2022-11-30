// Generated from /home/azizbek/Desktop/UNIST/principles/hw3/src/main/antlr4/MiniScalaLexer.g4 by ANTLR 4.8
package hw3;
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MiniScalaLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		WS=1, INT=2, VAR=3, VAL=4, DEF=5, PLUS=6, MINUS=7, STAR=8, SLASH=9, SEMI=10, 
		ARROW=11, GT=12, GEQ=13, ASN=14, ISZERO=15, IF=16, THEN=17, ELSE=18, EQ=19, 
		LPAREN=20, RPAREN=21, LBRACKET=22, RBRACKET=23, ID=24;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"WS", "INT", "VAR", "VAL", "DEF", "PLUS", "MINUS", "STAR", "SLASH", "SEMI", 
			"ARROW", "GT", "GEQ", "ASN", "ISZERO", "IF", "THEN", "ELSE", "EQ", "LPAREN", 
			"RPAREN", "LBRACKET", "RBRACKET", "ID", "DIGIT", "ALPHA"
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


	public MiniScalaLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "MiniScalaLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\32\u008b\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\3\2\6\29\n\2\r\2\16\2:\3\2\3\2\3\3\6\3@\n\3"+
		"\r\3\16\3A\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3\b"+
		"\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3\r\3\r\3\16\3\16\3\16\3\17"+
		"\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3\22\3\22"+
		"\3\22\3\22\3\22\3\23\3\23\3\23\3\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26"+
		"\3\27\3\27\3\30\3\30\3\31\6\31\u0084\n\31\r\31\16\31\u0085\3\32\3\32\3"+
		"\33\3\33\2\2\34\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31"+
		"\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\2\65\2"+
		"\3\2\5\4\2\13\f\"\"\3\2\62;\4\2C\\c|\2\u008b\2\3\3\2\2\2\2\5\3\2\2\2\2"+
		"\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2"+
		"\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2"+
		"\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2"+
		"\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\38\3\2\2\2"+
		"\5?\3\2\2\2\7C\3\2\2\2\tG\3\2\2\2\13K\3\2\2\2\rO\3\2\2\2\17Q\3\2\2\2\21"+
		"S\3\2\2\2\23U\3\2\2\2\25W\3\2\2\2\27Y\3\2\2\2\31\\\3\2\2\2\33^\3\2\2\2"+
		"\35a\3\2\2\2\37d\3\2\2\2!k\3\2\2\2#n\3\2\2\2%s\3\2\2\2\'x\3\2\2\2)z\3"+
		"\2\2\2+|\3\2\2\2-~\3\2\2\2/\u0080\3\2\2\2\61\u0083\3\2\2\2\63\u0087\3"+
		"\2\2\2\65\u0089\3\2\2\2\679\t\2\2\28\67\3\2\2\29:\3\2\2\2:8\3\2\2\2:;"+
		"\3\2\2\2;<\3\2\2\2<=\b\2\2\2=\4\3\2\2\2>@\5\63\32\2?>\3\2\2\2@A\3\2\2"+
		"\2A?\3\2\2\2AB\3\2\2\2B\6\3\2\2\2CD\7x\2\2DE\7c\2\2EF\7t\2\2F\b\3\2\2"+
		"\2GH\7x\2\2HI\7c\2\2IJ\7n\2\2J\n\3\2\2\2KL\7f\2\2LM\7g\2\2MN\7h\2\2N\f"+
		"\3\2\2\2OP\7-\2\2P\16\3\2\2\2QR\7/\2\2R\20\3\2\2\2ST\7,\2\2T\22\3\2\2"+
		"\2UV\7\61\2\2V\24\3\2\2\2WX\7=\2\2X\26\3\2\2\2YZ\7?\2\2Z[\7@\2\2[\30\3"+
		"\2\2\2\\]\7@\2\2]\32\3\2\2\2^_\7@\2\2_`\7?\2\2`\34\3\2\2\2ab\7<\2\2bc"+
		"\7?\2\2c\36\3\2\2\2de\7k\2\2ef\7u\2\2fg\7|\2\2gh\7g\2\2hi\7t\2\2ij\7q"+
		"\2\2j \3\2\2\2kl\7k\2\2lm\7h\2\2m\"\3\2\2\2no\7v\2\2op\7j\2\2pq\7g\2\2"+
		"qr\7p\2\2r$\3\2\2\2st\7g\2\2tu\7n\2\2uv\7u\2\2vw\7g\2\2w&\3\2\2\2xy\7"+
		"?\2\2y(\3\2\2\2z{\7*\2\2{*\3\2\2\2|}\7+\2\2},\3\2\2\2~\177\7}\2\2\177"+
		".\3\2\2\2\u0080\u0081\7\177\2\2\u0081\60\3\2\2\2\u0082\u0084\5\65\33\2"+
		"\u0083\u0082\3\2\2\2\u0084\u0085\3\2\2\2\u0085\u0083\3\2\2\2\u0085\u0086"+
		"\3\2\2\2\u0086\62\3\2\2\2\u0087\u0088\t\3\2\2\u0088\64\3\2\2\2\u0089\u008a"+
		"\t\4\2\2\u008a\66\3\2\2\2\6\2:A\u0085\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}