#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    int items[MAX];
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    }
}

int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1;
}

int peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}



void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}



int evaluatePostfix(char* postfix) {
    struct Stack s;
    initStack(&s);
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = pop(&s);
            int val1 = pop(&s);
            int res = applyOp(val1, val2, ch);
            push(&s, res);
        }
    }
    return pop(&s);
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression (e.g., (2+3)*4): ");
    if (fgets(infix, MAX, stdin) != NULL) {
        size_t len = strlen(infix);
        if (len > 0 && infix[len - 1] == '\n') {
            infix[len - 1] = '\0';
        }
    }

    infixToPostfix(infix, postfix);

    printf("\nPostfix Version: %s\n", postfix);
    printf("Final Result: %d\n", evaluatePostfix(postfix));

    return 0;
}