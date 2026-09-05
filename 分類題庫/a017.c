#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculate (int value1, int value2, char operator){
    switch(operator){
    case '*':
        return value1 * value2;
    case '/':
        return value1 / value2;
    case '%':
        return value1 % value2;
    case '+':
        return value1 + value2;
    case '-':
        return value1 - value2;
    default:
        return 0;
    }
}

int priority(char op) {
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void pop_and_calc(int number_stack[], int *top_num, char operator_stack[], int *top_op) {
    char op = operator_stack[--(*top_op)];

    int b = number_stack[--(*top_num)];
    int a = number_stack[--(*top_num)];

    number_stack[(*top_num)++] = calculate(a, b, op);
}

int main(void) {
    char present[100];

    int number_stack[200];
    int top_num = 0;

    char operator_stack[200];
    int top_op = 0;

    while (scanf("%s", present) != EOF) {

        if (strcmp(present, "(") == 0) {
            operator_stack[top_op++] = '(';
        } else if (strcmp(present, ")") == 0) {
            while (top_op > 0 && operator_stack[top_op - 1] != '(') {
                pop_and_calc(number_stack, &top_num, operator_stack, &top_op);
            }

            if (top_op > 0 && operator_stack[top_op - 1] == '(') {
                top_op--;
            }
        } else if (strcmp(present, "+") == 0 || strcmp(present, "-") == 0 ||
                 strcmp(present, "*") == 0 || strcmp(present, "/") == 0 || strcmp(present, "%") == 0) {
            
            char current_op = present[0];

            while (top_op > 0 && priority(current_op) <= priority(operator_stack[top_op - 1])) {
                pop_and_calc(number_stack, &top_num, operator_stack, &top_op);
            }

            operator_stack[top_op++] = current_op;
        } else {
            number_stack[top_num++] = atoi(present);
        }

        char next_char = getchar();
        if (next_char == '\n' || next_char == EOF) {
            
            while (top_op > 0) {
                pop_and_calc(number_stack, &top_num, operator_stack, &top_op);
            }

            if (top_num > 0) {
                printf("%d\n", number_stack[0]);
            }

            top_num = 0;
            top_op = 0;

            if (next_char == EOF) break;
        }
    }

    return 0;
}
