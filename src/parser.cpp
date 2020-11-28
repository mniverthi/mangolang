/*
    program ::= {statement}
    statement ::= "PRINT" (expression | string) nl
        | "IF" comparison "THEN" nl {statement} "ENDIF" nl
        | "WHILE" comparison "REPEAT" nl {statement} "ENDWHILE" nl
        | "LABEL" ident nl
        | "GOTO" ident nl
        | "LET" ident "=" expression nl
        | "INPUT" ident nl
    comparison ::= expression (("==" | "!=" | ">" | ">=" | "<" | "<=") expression)+
    expression ::= term {( "-" | "+" ) term}
    term ::= unary {( "/" | "*" ) unary}
    unary ::= ["+" | "-"] primary
    primary ::= number | ident
    nl ::= '\n'+
*/
#include "parser.hpp"
using namespace std;
Parser::Parser(Lexer* lex) {
    lexer = lex;
    curr = nullptr;
    peek = nullptr;
}
void Parser::abort(string message) {
    cout << "Parsing error: " << message << endl;
    cout << "Occurred at: \t" << "Line " << lexer.getCurrentLine() << ", Character " << lexer.getCurrentLinePos() << endl;
    exit(EXIT_FAILURE);
}