#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    char items[MAX];
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char c) {
    if (isFull(s)) {
        exit(1);
    }
    s->items[++(s->top)] = c;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}

int checkBalanced(char *exp) {
    int i = 0;
    struct Stack s;
    initStack(&s);

    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(&s, exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (isEmpty(&s)) {
                return 0;
            }
            char popped = pop(&s);
            if (!isMatchingPair(popped, exp[i])) {
                return 0;
            }
        }
        i++;
    }

    if (isEmpty(&s))
        return 1; 
    else
        return 0;
}

int main() {
    char exp[MAX];
    
    printf("Enter a mathematical expression:\n");
    scanf("%[^\n]", exp);

    if (checkBalanced(exp)) {
        printf("Balanced\n");
    } else {
                printf("Not Balanced\n");
 }
return 0;
}