#include<stdio.h>
#include<stdlib.h>

typedef struct _listnode {
    int num;
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

void insertNode(ListNode **pHead, int index, int value);

void removeNode(ListNode **ptrHead, int index);

void push(Stack *s, int item);

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
        printf("%d ", current->num);
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

void insertNode(ListNode **pHead, int index, int value) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->num = value;
    newNode->next = NULL;
    ListNode *current = *pHead;
    if (index == 0) {
        newNode->next = *pHead;
        *pHead = newNode;
    } else {
        findNode(* pHead, index - 1);
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

int main()
{
    Stack *s = malloc(sizeof(Stack));
    s->ll.size = 0;
    s->ll.head = NULL;
    printList(s->ll.head);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printList(s->ll.head);
    printf("Phan tu o dinh ngan xep: %d\n", peek(s));
    printf("Lay phan tu ra khoi ngan xep: %d\n", pop(s));
    printList(s->ll.head);

    push(s, 40);

    printList(s->ll.head);

    while (!isEmptyStack(s)) {
        printf("Lay phan tu ra khoi ngan xep: %d\n", pop(s));
    }
    printf("Ngan xep da rong\n");
    free(s);
    return 0;


}