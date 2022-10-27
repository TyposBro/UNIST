parser grammar IntParserAntlr4;

options {tokenVocab=IntLexer;}

program: expr EOF;
expr: integer
    | id
    | expr (PLUS | MINUS | STAR) expr
    | SIGMA expr expr expr
    | POW expr expr
    ;
integer: INT | MINUS INT;
id: ID;
