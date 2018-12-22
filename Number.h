//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_NUMBER_H
#define ORI_LEXER_NUMBER_H


#include "Expression.h"

class Number: public Expression {
    double value;

public:
    explicit Number(double value);
    double calculate() override;
};


#endif //ORI_LEXER_NUMBER_H
