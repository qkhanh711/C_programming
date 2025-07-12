#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int rear;
    int front;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int is_empty(Queue *q){
    return q->front > q->rear;
}

int is_full(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value){
    if (is_full(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue *q){
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    printf("o 1 %d\n", q->data[q->front]);
    // printf("o 2 %d\n", q->data[++q->front]);
    int value = q->data[q->front++];
    if (is_empty(q)) {
        q->front = 0;
        q->rear = -1;
    }
    return value;
}

int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    printf("%d\n", q->data[q->front]);
    return q->data[q->front];
}

int main(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    initQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // printf("o %d\n", peek(q));

    for (int i = 0; i < 2; i++) {
        // printf("o %d %d\n", i + 1, dequeue(q));
        peek(q);
    }

    while (!is_empty(q)) {
        printf("\t+ %d\n", dequeue(q));
    }

    free(q);
    return 0;
}
