
lexer grammar MiniScalaLexer;

WS: [ \t\n]+ -> skip;

INT : DIGIT+ ;

VAR: 'var';
VAL: 'val';
DEF: 'def';
PLUS: '+';
MINUS: '-';
STAR: '*';
SLASH: '/';
SEMI: ';';
ARROW: '=>';
GT: '>';
GEQ: '>=';
ASN: ':=';
ISZERO: 'iszero';
IF: 'if';
THEN: 'then';
ELSE: 'else';
EQ: '=';
LPAREN: '(';
RPAREN: ')';
LBRACKET: '{';
RBRACKET: '}';
ID: ALPHA+;
fragment DIGIT: [0-9];
fragment ALPHA: [a-zA-Z];
