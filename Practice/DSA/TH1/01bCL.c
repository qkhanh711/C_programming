#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;

void printList(ListNode *head);

ListNode* findNode(ListNode *head, int i);

void insertNode(ListNode **pHead, int index, int value);

void removeNode(ListNode **ptrHead, int index);

int main(void) {
    ListNode *node0, *node1, *head;
    node0 = malloc(sizeof(ListNode));
    node1 = malloc(sizeof(ListNode));
    node0->num = 20;
    node1->num = 30;
    node0->next = node1;
    node1->next = node0;
    head = node0;

    printf("Initial list: ");
    printList(head);

    insertNode(&head, 1, 25);
    printf("After inserting 25 at index 1: ");
    printList(head);

    insertNode(&head, 0, 10);
    printf("After inserting 10 at index 0: ");
    printList(head);

    removeNode(&head, 2);
    printf("After removing index 2: ");
    printList(head);

    return 0;
}

void printList(ListNode *head) {
    if (head == NULL) {
        printf("Dang sach lien ket rong.\n");
        return;
    }
    ListNode *p = head;
    do {
        printf("%d ", p->num);
        p = p->next;
    } while (p != head);
    printf("\n");
}

ListNode* findNode(ListNode *head, int i) {
    ListNode *cur = head;
    if ((head == NULL)|| (i<0)){
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;       
    }
    while (i> 0){
        cur = cur->next;
        i--;
        if (cur == head){
            printf("Phan tu tim kiem khong ton tai");
            return NULL;
        }   
    }
    return cur;  
}

void insertNode(ListNode **pHead, int index, int value) {
    ListNode *cur, *newNode;
    if (*pHead == NULL || index == 0) {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        if (*pHead == NULL) {
            *pHead = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = *pHead;
            ListNode *tail = findNode(*pHead, -1);
            tail->next = newNode;
            *pHead = newNode;
        }
    } else if ((cur = findNode(*pHead, index - 1)) != NULL) {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    } else {printf("can not insert the new item at index %d!\n", index);}
    
}

void removeNode(ListNode **ptrHead, int index) {
    ListNode *cur, *pre;
    if (index == 0) {
        cur = *ptrHead;
        if (cur->next == *ptrHead) {
            free(cur);
            *ptrHead = NULL;
        } else {
            pre = findNode(*ptrHead, index - 1);
            cur = pre->next;
            pre->next = cur->next;
            free(cur);
        }
    } else {
        pre = findNode(*ptrHead, index - 1);
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
}
