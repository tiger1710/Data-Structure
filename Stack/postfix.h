#include "stack.h"

#ifndef POSTFIX_H
#define POSTFIX_H

int prec(char op);

void infix_to_postfix(char exp[], char des[]);

element eval(char exp[]);

#endif
