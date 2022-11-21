parser grammar MiniScalaParser;

options {tokenVocab=MiniScalaLexer;}

program: expr EOF;
expr: integer
    | id
    | expr (PLUS | MINUS | STAR | SLASH | GT | GEQ) expr
    | iszero
    | ite
    | val
    | var
    | proc
    | def
    | id ASN expr
    | expr SEMI expr
    | expr expr
    | LPAREN expr RPAREN
    | LBRACKET expr RBRACKET
    ;
iszero: ISZERO expr;
ite: IF expr THEN expr ELSE expr;
val: LBRACKET VAL id EQ expr SEMI expr RBRACKET;
var: LBRACKET VAR id EQ expr SEMI expr RBRACKET;
proc: LPAREN id RPAREN ARROW expr;
def: LBRACKET DEF id LPAREN id RPAREN EQ expr SEMI expr RBRACKET;

 
integer: INT;
id: ID;
