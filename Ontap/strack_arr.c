#include<stdio.h>
#include<stdlib.h>

#define MAX 10
typedef struct {
    int data[MAX];
    int top;
    int size;
} Stack;

void init_stack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    s->top = -1;
    // int size = 0;
}

int is_empty(Stack *s) {
    if (s == NULL) {
        printf("Stack is NULL\n");
        return 0;
    }
    if (s->top == -1) {
        printf("Stack is empty\n");
        return 1;
    }
    return 0;
}

int full_stack(Stack *s) {
    if (s == NULL) {
        printf("Stack is NULL\n");
        return 0;
    }
    if (s->top >= MAX - 1) {
        printf("Stack is full\n");
        return 1;
    }
    return 0;
}


void push(Stack *s, int value) {
    if (full_stack(s)) {
        printf("Stack Overflow\n");
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}


int main(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;

    int arr[4] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++) {
        push(s, arr[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("Popped value: %d\n", pop(s));
    }
}

