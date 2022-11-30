
lexer grammar MiniCLexer;

WS: [ \t\n]+ -> skip;

INT : DIGIT+ ;

SKIPVAL: 'skip';
TRUE: 'true';
FALSE: 'false';
NOT: 'not';
WHILE: 'while';
LET: 'let';
IN: 'in';
PROC: 'proc';
PLUS: '+';
MINUS: '-';
STAR: '*';
SLASH: '/';
EQQ: '==';
LTE: '<=';
COMMA: ',';
ASN: ':=';
ISZERO: 'iszero';
IF: 'if';
THEN: 'then';
ELSE: 'else';
EQ: '=';
LPAREN: '(';
RPAREN: ')';
LANGLE: '<';
RANGLE: '>';
LBRACKET: '{';
RBRACKET: '}';
DOT: '.';
BEGIN: 'begin';
END: 'end';
SEMI: ';';
ID: ALPHA+;
fragment DIGIT: [0-9];
fragment ALPHA: [a-zA-Z];
