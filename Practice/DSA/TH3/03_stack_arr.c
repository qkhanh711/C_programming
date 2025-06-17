#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s);

int isEmptyStack(Stack *s);

void push(Stack *s, int value);

int pop(Stack *s);

int peek(Stack *s);

void initStack(Stack *s) {
    s->top = -1;
}


// 3) Hoàn thiện hàm isEmptyStack()
int isEmptyStack(Stack *s) {
    if (s == NULL) {
        return -1;
    }
    return s->top == 0;
}

// 4) Hoàn thiện hàm push()
void push(Stack *s, int value) {
    if (s->top >= MAX - 1) {
        printf("Stack Overflow");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

// 5) Hoàn thiện hàm pop()
int pop(Stack *s) {
    if (isEmptyStack(s)) {
       printf("Stack Underflow");
        return -1;
    }
    return s->data[ (s->top)-- ];
}

// 6) Hoàn thiện hàm peek()
int peek(Stack *s) {
    if (isEmptyStack(s)) {
    printf("Stack is empty");
    return -1;
    }
    return s->data[ s->top ];
}

int main(){
    Stack *s = malloc(sizeof(Stack));
    initStack(s);
    printf("Stack is empty: %d\n", isEmptyStack(s));

    push(s, 5);
    push(s, 10);
    push(s, 15);

    for (int i = 0; i < s->top + 1; i++) {
        printf("%d ", s->data[i]);
    }

    
    printf("\n Peak %d \n", peek(s));
    printf("%d \n", s->top);

    while (!isEmptyStack(s)) {
        printf("Pop: %d\n", pop(s));
    }

    printf("Stack is empty: %d\n", pop(s));
    printf("Stack is empty: %d\n", peek(s));
}