grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' statement* return_stmt '}' ;

statement : assign_statement  
    ;

assign_statement: 'int' VARIABLE '=' CONST ';' # const
    | 'int' VARIABLE '=' VARIABLE ';' # variable
    ;
    
return_stmt: RETURN CONST ';' ;

RETURN : 'return' ;
CONST : [0-9]+ ;
VARIABLE : [a-zA-Z]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
