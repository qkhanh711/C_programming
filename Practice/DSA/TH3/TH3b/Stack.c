#include<stdio.h>
#include<stdlib.h>

typedef struct _listnode {
    char num;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
    ListNode * head;
    int size;
} LinkedList;

typedef struct _stack {
    LinkedList ll;
} Stack;

void printList(ListNode *head);

ListNode* findNode(ListNode *head, int i);

void insertNode(ListNode **pHead, int index, char value);

void removeNode(ListNode **ptrHead, int index);

void push(Stack *s,  int item);

int pop(Stack *s);

int peek(Stack *s);

int isEmptyStack(Stack *s);

void printList(ListNode *head) {
    if (head == NULL) {
        printf("Danh sach lien ket khong co phan tu nao\n");
        return;
    }
    ListNode *current = head;
    while (current != NULL) {
        printf("%c ", current->num);
        current = current->next;
    }
    printf("\n");
}

ListNode* findNode(ListNode *head, int i) {
    ListNode *current = head;
    while (i>0 && head != NULL) {
        current = current->next;
        i--;
    }
    if (current == NULL) {
        printf("Khong tim thay node thu %d\n", i);
        return NULL;
    }
    return current;
}

void insertNode(ListNode **pHead, int index, char value) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->num = value;
    newNode->next = NULL;
    ListNode *current = *pHead;
    if (index == 0) {
        newNode->next = *pHead;
        *pHead = newNode;
    } else {
        for (int i = 0; i < index - 1; i++){
            current = current->next;
        }
        if (current == NULL) {
            printf("Khong tim thay node thu %d\n", index);
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

}

void removeNode(ListNode **ptrHead, int index){
    if (*ptrHead == NULL) {
        printf("Khong the xoa node tai vi tri %d\n", index);
        return;
    }
    ListNode *current = *ptrHead;
    if (index == 0){
        *ptrHead = current->next;
        free(current);
    } else {
        ListNode *prev = findNode(*ptrHead, index - 1);
        if (prev == NULL || prev->next == NULL) {
            printf("Khong tim thay node thu %d\n", index);
            return;
        }
        current = prev->next;
        prev->next = current->next;
        free(current);
    }

}


void push(Stack *s, int item) {
    insertNode( &(s->ll.head), 0, item);
    s->ll.size++;
}

int pop(Stack *s){
    if (isEmptyStack(s)){
        printf("Ngan xep rong\n");
        return -1;
    } else {
        // item = findNode(s->ll.head, s->ll.size - 1)->num;
        int item = s->ll.head->num;
        removeNode( &(s->ll.head), 0);
        s->ll.size--;
        return item;
    }
}

int peek(Stack *s) {
    if (isEmptyStack(s)){
        printf("Ngan xep rong\n");
        return -1;
    } else {
        // return findNode(s->ll.head, s->ll.size - 1)->num;
        return s->ll.head->num;
    }
}

int isEmptyStack(Stack *s){
    if (s->ll.size == 0){
        return 1;
    } else {
        return 0;
    }
}



int Bai1()
{
    
    FILE *inputFile = fopen("INPUT.txt", "r");
    FILE *outputFile = fopen("OUTPUT.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }

    Stack *s = malloc(sizeof(Stack));
    s->ll.size = 0;
    s->ll.head = NULL;

    char line[100];
    while (fgets(line, sizeof(line), inputFile)) {
        for (int i = 0; line[i] != '\0'; i++) {
            push(s, line[i]);
        }
        while (!isEmptyStack(s)) {
            fprintf(outputFile, "%c", pop(s));
        }
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    free(s);
    
    return 0;
}

int Bai2(){
    FILE *inputFile = fopen("INPUT.txt", "r");
    FILE *outputFile = fopen("OUTPUT.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }

    Stack *s = malloc(sizeof(Stack));
    s->ll.size = 0;
    s->ll.head = NULL;

    char line[100];
    while (fgets(line, sizeof(line), inputFile)) {
        // printf("Thuc hien lenh: %s\n", line); 
        switch (line[0])
        {
        case '2':
            // printf("Thuc hien lenh push(%c)\n", line[2]);
            push(s, line[2]);
            break;
        case '1':
            pop(s);
            break;
        default:
            break;
        }
    }    
    while (!isEmptyStack(s)) {
        fprintf(outputFile, "%c\n", pop(s));
    }
    fprintf(outputFile, "\n");
    return 0;

}

int main()
{
    FILE *inputFile = fopen("INPUT.txt", "r");
    FILE *outputFile = fopen("OUTPUT.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }


    char line[100];
    while (fgets(line, sizeof(line), inputFile)) {
        Stack *s = malloc(sizeof(Stack));
        s->ll.size = 0;
        s->ll.head = NULL;
        // printf("Thuc hien lenh: %s\n", line); 
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '(' || line[i] == '[' || line[i] == '{') { 
                push(s, line[i]);
            }
            int top = peek(s);
            if (top == '(' && line[i+1] == ')') {
                pop(s);
            } else if (top == '[' && line[i+1] == ']') {
                pop(s);
            } else if (top == '{' && line[i+1] == '}') {
                pop(s);
            }              
        }
        if (isEmptyStack(s)) {
                fprintf(outputFile, "YES\n");
        } else {
                fprintf(outputFile, "NO\n");
        }
    }
    fprintf(outputFile, "\n");
    return 0;
}