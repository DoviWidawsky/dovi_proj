#include <string>
#include <list>
#include <map>
#include <iostream>
#include "VarData.h"
#include "Command.h"
#include "CommandFactory.h"
#include "CmdsCollection.h"
#include "ExpsCollection.h"
#include "Threads.h"

class Interpreter {
    map<string, VarData*> symTbl;
    CommandFactory* factory;
    ExpsCollection* expressions;
    map<string,string> codeMap;
    Threads* threads;

public:
    Interpreter();
    ~Interpreter();
    vector< string> lexer(string input);
    void parser(vector<string> input);
};
