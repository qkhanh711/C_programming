#include<stdio.h>
#include<stdlib.h>

typedef struct _dlistnode{
    int num;
    struct _dlistnode *next;
    struct _dlistnode *prev;
} DListNode;

typedef struct DLinkedList {
    DListNode* head;
    DListNode* tail;
} DLinkedList;

void printList(DLinkedList* dl);

DListNode* findNode(DLinkedList* dl, int i);

void insertNode(DLinkedList* dl, int index, int value);

void removeNode(DLinkedList* dl, int index);

int main(void) {
    DLinkedList* dl = malloc(sizeof(DLinkedList));
    dl->head = NULL;
    dl->tail = NULL;

    DListNode* node0, *node1, *node2, *node3;
    node0 = malloc(sizeof(DListNode));
    node1 = malloc(sizeof(DListNode));
    node2 = malloc(sizeof(DListNode));
    node3 = malloc(sizeof(DListNode));
    node0->num = 10;
    node1->num = 20;
    node2->num = 30;
    node3->num = 40;

    node0->next = node1;
    node1->prev = node0;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = NULL;
    dl->head = node0;
    dl->tail = node3;
    printList(dl);
    insertNode(dl, 1, 25);
    printList(dl);
    removeNode(dl, 2);
    printList(dl);
 
}

void printList(DLinkedList* dl) {
    DListNode* p = dl->head;
    while (p != NULL) {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}

DListNode* findNode(DLinkedList* dl, int i) {
    DListNode *cur = dl->head;
    if ((dl->head == NULL) || (i < 0)) {
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }
    while (i>0){
        cur = cur->next;
        i--;
        if (cur == NULL) {
            printf("Phan tu tim kiem khong ton tai");
            return NULL;
        }
    }
    return cur;
}

// DListNode* findNode2(DLinkedList* dl, int i) {
//     DListNode *cur = dl->tail;
//     if ((dl->tail == NULL) || (i < 0)) {
//         printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
//         return NULL;
//     }
//     while (i>0){
//         cur = cur->prev;
//         i--;
//         if (cur == NULL) {
//             printf("Phan tu tim kiem khong ton tai");
//             return NULL;
//         }
//     }
//     return cur;
// }

void insertNode(DLinkedList* dl, int index, int value) {
    DListNode* cur, *newNode;
    if (dl->head == NULL || index == 0) {
        newNode = malloc(sizeof(DListNode));
        newNode->num = value;
        newNode->next = dl->head;
        newNode->prev = NULL;
        if (dl->head != NULL) {
            dl->head->prev = newNode;
        }
        dl->head = newNode;
        if (dl->tail == NULL) {
            dl->tail = newNode;
        }
    } else if ((cur = findNode(dl, index - 1)) != NULL) {
        newNode = malloc(sizeof(DListNode));
        newNode->num = value;
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next = newNode;
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        } else {
            dl->tail = newNode;
        }
    } else {
        printf("can not insert the new item at index %d!\n", index);
    }
}

void removeNode(DLinkedList* dl, int index) {
    DListNode* cur, *pre;
    if (index == 0) {
        cur = dl->head;
        dl->head = cur->next;
        if (dl->head != NULL) {
            dl->head->prev = NULL;
        } else {
            dl->tail = NULL;
        }
        free(cur);
    } else {
        pre = findNode(dl, index - 1);
        if (pre != NULL) {
            cur = pre->next;
            if (cur != NULL) {
                pre->next = cur->next;
                if (cur->next != NULL) {
                    cur->next->prev = pre;
                } else {
                    dl->tail = pre;
                }
                free(cur);
            }
        }
    }
}