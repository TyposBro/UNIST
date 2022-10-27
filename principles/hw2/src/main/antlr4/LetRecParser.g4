parser grammar LetRecParser;

options {tokenVocab=LetRecLexer;}

program: expr EOF;
expr: integer
    | id
    | expr (PLUS | MINUS) expr
    | ISZERO expr
    | IF expr THEN expr ELSE expr
    | LET id EQ expr IN expr
    | LETREC id LPAREN id RPAREN EQ expr IN expr
    | PROC id expr
    | LPAREN expr RPAREN
    | expr expr
    ;
integer: INT;
id: ID;
