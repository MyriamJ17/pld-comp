#pragma once
#include <map>
#include <string>

using namespace std;

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

class  AssignVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitConst(ifccParser::ConstContext *ctx) override;
        virtual antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override;
        AssignVisitor();
        ~AssignVisitor();

        private:
        std::map<std::string, int> variables;
};
