#include "CodeGenVisitor.h"

#include <string>

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
    std::cout<< ".globl main\n" ;
    std::cout<< " main: \n" ;
    for (int i = 0 ; i < ctx->statement().size() ; i++)
        this->visit( ctx->statement()[i] );
    this->visit( ctx->return_stmt() );
    
    std::cout << "    ret\n";

    return 0;
}


antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    int retval = stoi(ctx->CONST()->getText());

    std::cout << "    movl $"<<retval<<", %eax\n" ;

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitConst(ifccParser::ConstContext *ctx)
{
    string left = ctx->VARIABLE()->getText();
    int right = stoi(ctx->CONST()->getText());

    variables.insert(pair<string,int>(left,variables.size()*4));

    std::cout << "    movl $"<<right<< ", " << "-" << variables[left] << "(%rbp)" << "\n" ;

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx)
{
    string left = ctx->VARIABLE()[0]->getText();
    string right = ctx->VARIABLE()[1]-> getText();

    variables.insert(pair<string,int>(left,variables.size()*4));

    std::cout << "    movl -"<<variables[right]<< "(%rbp), " << "-" << variables[left] << "(%rbp)" << "\n" ;

    return 0;
}