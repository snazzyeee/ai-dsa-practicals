// Title: Expression Conversion (Infix to Postfix) and Evaluation Using a Stack
//
// Problem statement:
// Convert a valid infix expression to postfix notation and evaluate the resulting postfix
// expression using stacks. Operands and operators must be single characters. Allow operands,
// parentheses, and the operators +, -, *, /, and ^.

#if 1 // change 1 to 0 to use your full-program area below.

#include <stdio.h>

#define MAX 128

// PSEUDOCODE: write your steps here.
/*





*/

// PRACTICE: define your stack and stack operations here.

// PRACTICE: convert infix to postfix; return 1 on success, 0 on invalid input.
int infixToPostfix(const char infix[], char postfix[]){
    (void)infix; (void)postfix;
    printf("TODO: convert the expression.\n");
    return 0;
}

// PRACTICE: evaluate postfix; return 1 on success, 0 on invalid input.
int evaluatePostfix(const char postfix[], double *result){
    (void)postfix; (void)result;
    printf("TODO: evaluate the postfix expression.\n");
    return 0;
}

int main(void){
    char infix[MAX], postfix[MAX];
    double result;

    printf("Enter infix expression without spaces: ");
    if(scanf("%127s", infix) != 1) return 1;
    if(infixToPostfix(infix, postfix)){
        printf("Postfix: %s\n", postfix);
        if(evaluatePostfix(postfix, &result)){
            printf("Result: %g\n", result);
        }
    }
    return 0;
}

#else

// FULL PROGRAM: write your complete program here when practising from scratch.

#endif
