#include "brackets.h"
#include <stdlib.h>
#include <stdbool.h>

bool check_brackets(const char* exp) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    initialize(s);

    for (int i = 0; exp[i] != '\0'; i++) {
        element ch = exp[i];
        switch (ch) {
        case '(': case '{': case '[':
            push(s, ch);
            break;
        case ')': case '}': case ']':
            if (is_empty(s)) {
                finalize(s);
                return false;
            } else {
                element pair = peek(s); pop(s);
                if ((pair == '(' && ch != ')') ||
                    (pair == '{' && ch != '}') ||
                    (pair == '[' && ch != ']')) {
                    finalize(s);
                    return false;
                }
            }
            break;
        default:
            break;
        }
    }

    if (!is_empty(s)) return false;

    return true;
}
