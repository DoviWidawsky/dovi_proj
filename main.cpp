#include <iostream>
#include <cstring>
#include <list>
#include "interpeter.h"

using namespace std;

// test for lexer
int main() {
    interpeter interpeter1;

    list<string> l = interpeter1.lexer("I am Ori. This is so cool\n\toop\noop");

    for (auto &it : l)
        std::cout << it << endl;

    cout<<"this is stupid line"<<endl;
    return 0;
}