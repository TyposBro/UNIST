
lexer grammar LetRecLexer;

WS: [ \t\n]+ -> skip;

INT : DIGIT+ ;

LET: 'let';
IN: 'in';
PLUS: '+';
MINUS: '-';
LETREC: 'letrec';
ISZERO: 'iszero';
IF: 'if';
THEN: 'then';
ELSE: 'else';
EQ: '=';
LPAREN: '(';
RPAREN: ')';
PROC: 'proc';
ID: ALPHA+;
fragment DIGIT: [0-9];
fragment ALPHA: [a-zA-Z];
