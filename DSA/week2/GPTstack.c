#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
    ListNode *head;
    int size;
} LinkedList;

typedef struct _stack {
    LinkedList ll;
} Stack;

void printList(ListNode *head) {
    if (head == NULL) {
        printf("Danh sach lien ket khong co phan tu nao\n");
        return;
    }
    ListNode *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->num);
        cur = cur->next;
    }
    printf("\n");
}

ListNode* findNode(ListNode *head, int index) {
    if (head == NULL || index < 0) return NULL;
    while (index > 0 && head != NULL) {
        head = head->next;
        index--;
    }
    return head;
}

void insertNode(ListNode **pHead, int index, int value) {
    ListNode *newNode, *prev;

    if (index == 0) {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    } else {
        prev = findNode(*pHead, index - 1);
        if (prev != NULL) {
            newNode = malloc(sizeof(ListNode));
            newNode->num = value;
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }
}

void removeNode(ListNode **pHead, int index) {
    ListNode *temp, *prev;

    if (*pHead == NULL || index < 0) return;

    if (index == 0) {
        temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    } else {
        prev = findNode(*pHead, index - 1);
        if (prev != NULL && prev->next != NULL) {
            temp = prev->next;
            prev->next = temp->next;
            free(temp);
        }
    }
}

void push(Stack *s, int item) {
    insertNode(&(s->ll.head), 0, item); // Đưa vào đầu danh sách (đỉnh stack)
    s->ll.size++;
}

int pop(Stack *s) {
    int item;
    if (!isEmptyStack(s)) {
        item = s->ll.head->num;
        removeNode(&(s->ll.head), 0);
        s->ll.size--;
        return item;
    } else {
        printf("Ngan xep rong\n");
        return -1; // Hoặc một giá trị báo lỗi
    }
}

int peek(Stack *s) {
    if (!isEmptyStack(s))
        return s->ll.head->num;
    else {
        printf("Ngan xep rong\n");
        return -1; // Hoặc giá trị báo lỗi
    }
}

int isEmptyStack(Stack *s) {
    return (s->ll.size == 0);
}

int main() {
    Stack *s = malloc(sizeof(Stack));
    s->ll.size = 0;
    s->ll.head = NULL;

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Stack sau khi push 3 phan tu: ");
    printList(s->ll.head);

    printf("Phan tu o dinh stack (peek): %d\n", peek(s));

    printf("Pop: %d\n", pop(s));
    printf("Stack sau khi pop: ");
    printList(s->ll.head);

    printf("Pop: %d\n", pop(s));
    printf("Pop: %d\n", pop(s));
    printf("Pop tu ngan xep rong: %d\n", pop(s)); // nên báo lỗi

    free(s);
    return 0;
}

