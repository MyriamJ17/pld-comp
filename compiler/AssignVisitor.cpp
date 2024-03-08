#include "AssignVisitor.h"

antlrcpp::Any AssignVisitor::visitConst(ifccParser::ConstContext *ctx)
{
    string left = ctx->VARIABLE()->getText();
    int right = stoi(ctx->CONST()->getText());

    if (auto search = variables.find(left) ; search != variables.end()){
        std::cerr << "La variable " << left << " a déjà été déclarée :(" << endl;
        return -1;
    }

    variables.insert(left,variable.count()*4);

    std::cout << left<<"\n" ;

    return 0;
}

antlrcpp::Any AssignVisitor::visitVariable(ifccParser::VariableContext *ctx)
{
    string left = ctx->VARIABLE()->getText();
    string right = ctx->VARIABLE()->getText();

    if (auto search = variables.find(right) ; search == variables.end()){
        std::cerr << "La variable " << right << " n'a pas été déclarée :(" << endl;
        return -1;
    }
    if (auto search = variables.find(left) ; search != variables.end()){
        std::cerr << "La variable " << left << " a déjà été déclarée :(" << endl;
        return -1;
    }

    variables.insert(left,variable.count()*4);

    std::cout << left<<"\n" ;

    return 0;
}
