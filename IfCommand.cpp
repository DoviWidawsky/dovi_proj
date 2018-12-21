#include <utility>


#include <iostream>
#include "IfCommand.h"
#include "CommandFactory.h"
#include "Utils.h"
#include "Parser.h"


void IfCommand::doCommand() {
    int index = 1;
    Utils utils;
    Parser parser;
    list<string> condition;
    vector<string> blockCode;

    while (this->code[index] != "{") {
        cout << this->code[index] << endl;
        condition.push_back(this->code[index]);
        index++;
    }
    index += 2;
    for (index; index < this->code.size(); ++index) {
        blockCode.push_back(this->code[index]);
    }

    if (utils.evaluate(condition, this->symTbl)->calculate()) {
        parser.parse(blockCode, this->expressions, this->factory, this->cmdMap);
        this->expressions->executeAll();
    }
}

IfCommand::IfCommand(vector<string> &code, CommandFactory *factory, map<string, VarData *> *symTbl, map<string,string> *cmdMap) {
    for (const auto &i : code) {
        this->code.push_back(i);
    }
    this->factory=factory;
    this->symTbl=symTbl;
    this->cmdMap= cmdMap;
    this->expressions=new ExpsCollection;
}

IfCommand::~IfCommand() {
    delete this->expressions;
}