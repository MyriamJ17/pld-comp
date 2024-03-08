grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' return_stmt '}' ;
assign_statement: VARIABLE '=' CONST # const
    | VARIABLE '=' VARIABLE # variable
    ;
return_stmt: RETURN CONST ';' ;

RETURN : 'return' ;
CONST : [0-9]+ ;
VARIABLE : [a-zA-Z]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
