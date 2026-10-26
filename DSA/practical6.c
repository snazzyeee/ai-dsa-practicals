// Title: Expression Conversion (Infix to Postfix) and Evaluation Using a Stack
//
// Problem statement:
// Convert a valid infix expression to postfix notation and evaluate the resulting postfix
// expression using stacks. Operands and operators must be single characters. Allow operands,
// parentheses, and the operators +, -, *, /, and ^.

#if 1 // change 1 to 0 to use your full-program area below.

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 128

// PSEUDOCODE: write your steps here.
/*





*/

int precedence(char op){
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// PRACTICE: convert infix to postfix; return 1 on success, 0 on invalid input.
int infixToPostfix(const char infix[], char postfix[]){
    char stack[MAX];
    int top = -1, out = 0, expectOperand = 1;

    for(int i = 0; infix[i] != '\0'; i++){
        unsigned char ch = (unsigned char)infix[i];
        if(isalnum(ch)){
            if(!expectOperand) return 0;
            postfix[out++] = (char)ch;
            expectOperand = 0;
        }else if(ch == '('){
            if(!expectOperand) return 0;
            stack[++top] = (char)ch;
        }else if(ch == ')'){
            if(expectOperand) return 0;
            while(top >= 0 && stack[top] != '(') postfix[out++] = stack[top--];
            if(top < 0) return 0;
            top--;
        }else if(precedence((char)ch)){
            if(expectOperand) return 0;
            // ^ is right associative, so equal ^ operators stay on the stack.
            while(top >= 0 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence((char)ch) ||
                   (precedence(stack[top]) == precedence((char)ch) && ch != '^'))){
                postfix[out++] = stack[top--];
            }
            stack[++top] = (char)ch;
            expectOperand = 1;
        }else return 0;
    }
    if(expectOperand) return 0;
    while(top >= 0){
        if(stack[top] == '(') return 0;
        postfix[out++] = stack[top--];
    }
    postfix[out] = '\0';
    return 1;
}

// PRACTICE: evaluate postfix; return 1 on success, 0 on invalid input.
int evaluatePostfix(const char postfix[], double *result){
    double stack[MAX], values[256] = {0};
    int known[256] = {0}, top = -1;

    for(int i = 0; postfix[i] != '\0'; i++){
        unsigned char ch = (unsigned char)postfix[i];
        if(isdigit(ch)){
            stack[++top] = ch - '0';
        }else if(isalpha(ch)){
            if(!known[ch]){
                printf("Enter value for %c: ", ch);
                if(scanf("%lf", &values[ch]) != 1 || !isfinite(values[ch])) return 0;
                known[ch] = 1;
            }
            stack[++top] = values[ch];
        }else{
            if(top < 1) return 0;
            double right = stack[top--], left = stack[top--], value;
            if(ch == '+') value = left + right;
            else if(ch == '-') value = left - right;
            else if(ch == '*') value = left * right;
            else if(ch == '/'){
                if(right == 0) return 0;
                value = left / right;
            }else if(ch == '^') value = pow(left, right);
            else return 0;
            if(!isfinite(value)) return 0;
            stack[++top] = value;
        }
    }
    if(top != 0) return 0;
    *result = stack[top];
    return 1;
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
        }else printf("Unable to evaluate expression.\n");
    }else printf("Invalid infix expression.\n");
    return 0;
}

#else

// FULL PROGRAM: write your complete program here when practising from scratch.

#endif
