parser grammar MiniCParser;

options {tokenVocab=MiniCLexer;}

program: expr EOF;
expr: skipval | trueval | falseval
    | integer
    | id
    | expr (PLUS | MINUS | STAR | SLASH | LTE | EQQ) expr
    | ite
    | whileexp
    | let
    | proc
    | not
    | expr LPAREN expr (COMMA expr)* RPAREN
    | expr LANGLE id (COMMA id)* RANGLE
    | id ASN expr
    | records
    | expr DOT id
    | expr DOT id ASN expr
    | expr SEMI expr
    | BEGIN expr END
    ;

ite: IF expr THEN expr ELSE expr;
whileexp: WHILE expr expr;

let: LET id EQ expr IN expr;
proc: PROC LPAREN id (COMMA id)* RPAREN expr;

records: LBRACKET record_entry? (COMMA record_entry)* RBRACKET;
record_entry: id ASN expr;


not: NOT expr;
skipval: SKIPVAL;
trueval: TRUE;
falseval: FALSE;
integer: INT;
id: ID;
