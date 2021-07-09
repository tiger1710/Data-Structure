#include "postfix.h"
#include <stdlib.h>

int prec(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[], char des[]) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    initialize(s);
    int k = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        switch (ch) {
        case '+': case '-': case '*': case '/':
            while (!is_empty(s) && prec(ch) <= prec(peek(s))) {
                des[k++] = peek(s);
                pop(s);
            }
            push(s, ch);
            break;
        case '(':
            push(s, ch);
            break;
        case ')':
            while (peek(s) != '(') {
                des[k++] = peek(s);
                pop(s);
            }
            pop(s);
            break;
        default:
            des[k++] = ch;
            break;
        }
    }

    while (!is_empty(s)) {
        des[k++] = peek(s);
        pop(s);
    }
    des[k] = 0;

    finalize(s);
}

element eval(char exp[]) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    initialize(s);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            element value = ch - '0';
            push(s, value);
        } else {
            element op2 = peek(s); pop(s);
            element op1 = peek(s); pop(s);
            switch (ch) {
            case '+':
                push(s, op1 + op2);
                break;
            case '-':
                push(s, op1 - op2);
                break;
            case '*':
                push(s, op1 * op2);
                break;
            case '/':
                push(s, op1 / op2);
                break;
            default:
                break;
            }
        }
    }

    int result = peek(s);
    finalize(s);
    return result;
}
