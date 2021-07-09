#include <stdio.h>
#include "brackets.h"
#include "postfix.h"

int main(void) {
    char exp1[] = "8/2-3+3*2";

    char res[32];
    int ans;
    printf("중위표기식: %s\n", exp1);
    infix_to_postfix(exp1, res);
    printf("후위표기식: %s\n", res);
    ans = eval(res);
    printf("값: %d\n", ans);


    return 0;
}
