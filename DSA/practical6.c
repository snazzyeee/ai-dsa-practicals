// Title: Expression Conversion (Infix to Postfix) and Evaluation Using a Stack
//
// Problem statement:
// Convert a valid infix expression to postfix notation and evaluate the resulting postfix
// expression using stacks. Operands and operators must be single characters. Allow operands,
// parentheses, and the operators +, -, *, /, and ^.

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 128


int precedence(char op){
    if(op == '^') return 3; 
    if(op == '*' || op == '/') return 2; 
    if(op == '+' || op == '-') return 1; 
    return 0; 
}



int infixToPostfix(char infix[], char postfix[]){
    char stack[MAX]; 
    int top = -1, out = 0; 

    for(int i = 0; infix[i] != '\0'; i++){ 
        unsigned char ch = (unsigned char)infix[i]; 
        if(isalnum(ch)){
            postfix[out++] = (char)ch; 
        }else if(ch == '('){
            stack[++top] = (char)ch; 
        }else if(ch == ')'){
            while(top >= 0 && stack[top] != '(') postfix[out++] = stack[top--]; 
            if(top < 0) return 0;
            top--;
        }else if(precedence((char)ch)){
            
            while(top >= 0 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence((char)ch) ||
                   (precedence(stack[top]) == precedence((char)ch) && ch != '^'))){
                postfix[out++] = stack[top--]; 
            }
            stack[++top] = (char)ch;
        }else return 0;
    }
    while(top >= 0){
        if(stack[top] == '(') return 0;
        postfix[out++] = stack[top--];
    }
    postfix[out] = '\0'; 
    return 1;
}



// Pop the right operand before the left one.
int evaluatePostfix(char postfix[], double *result){
    double stack[MAX], values[256] = {0}; 
    int known[256] = {0}, top = -1; 

    for(int i = 0; postfix[i] != '\0'; i++){
        unsigned char ch = (unsigned char)postfix[i];
        if(isdigit(ch)){
            stack[++top] = ch - '0'; 
        }else if(isalpha(ch)){
            if(!known[ch]){
                printf("Enter value for %c: ", ch);
                scanf("%lf", &values[ch]);
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
    int choice;

    do{
        printf("\n1: Convert and evaluate  2: Exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter infix expression without spaces: ");
            scanf("%127s", infix);
            if(infixToPostfix(infix, postfix)){
                printf("Postfix: %s\n", postfix);
                if(evaluatePostfix(postfix, &result)) printf("Result: %g\n", result);
                else printf("Unable to evaluate expression.\n");
            }else printf("Invalid infix expression.\n");
            break;
        case 2: break;

        }
    }while(choice != 2);
    return 0;
}

