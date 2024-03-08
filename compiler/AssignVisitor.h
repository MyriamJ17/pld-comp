#pragma once
#include <map>


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

class  AssignVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitConst(ifccParser::ConstContext *ctx) override;
        virtual antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override;

        private:
        std::map<std::string, int> variables;
};
