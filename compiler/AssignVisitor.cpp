#include "AssignVisitor.h"
#include <string>

using namespace std;

antlrcpp::Any AssignVisitor::visitConst(ifccParser::ConstContext *ctx)
{
    string left = ctx->VARIABLE()->getText();
    int right = stoi(ctx->CONST()->getText());
    
    if (auto search = variables.find(left) ; search != variables.end()){
        std::cerr << "La variable " << left << " a déjà été déclarée :(" << endl;
        return -1;
    }

    variables.insert(pair<string,int>(left,variables.size()*4));

    std::cout << left<<"\n" ;

    return 0;
}

antlrcpp::Any AssignVisitor::visitVariable(ifccParser::VariableContext *ctx)
{
    string left = ctx->VARIABLE()[0]->getText();
    string right = ctx->VARIABLE()[1]-> getText();

    if (auto search = variables.find(right) ; search == variables.end()){
        std::cerr << "La variable " << right << " n'a pas été déclarée :(" << endl;
        return -1;
    }
    if (auto search = variables.find(left) ; search != variables.end()){
        std::cerr << "La variable " << left << " a déjà été déclarée :(" << endl;
        return -1;
    }

    variables.insert(pair<string,int>(left,variables.size()*4));

    std::cout << left<<"\n" ;

    return 0;
}

AssignVisitor::AssignVisitor()
{
    
}

AssignVisitor::~AssignVisitor()
{
}
