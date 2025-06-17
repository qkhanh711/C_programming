#include<stdio.h>
#include<stdlib.h>

typedef struct CDlistNode {
    int num;
    struct CDlistNode* next;
    struct CDlistNode* prev;
} CDlistNode;

typedef struct {
    CDlistNode* head;
    CDlistNode* tail;
} CLinkedList;



void printList(CLinkedList* cl);

CDlistNode* findNode(CLinkedList* cl, int i);

void insertNode(CLinkedList* cl, int index, int value);

void removeNode(CLinkedList* cl, int index);

void printLoop1(CLinkedList* cl, int numloop){
    int i = 0;
    CDlistNode* p = cl->head;
    printf("%d ", p->num);
    do
    {
        p = p->next;
        printf("%d ", p->num);
        if (p->next == cl->head){
            i++;
            printf("\n");
        }
    } while (i<numloop);
    printf("\n");
}

void printLoop2(CLinkedList* cl, int numloop){
    int i = 0;
    CDlistNode* p = cl->tail;
    printf("%d ", p->num);
    do
    {
        p = p->next;
        printf("%d ", p->num);
        if (p->next == cl->tail){
            i++;
            printf("\n");
        }
    } while (i<numloop);
    printf("\n");
}

int main(void) {
    CLinkedList* cl = malloc(sizeof(CLinkedList));
    cl->head = NULL;
    cl->tail = NULL;

    CDlistNode* node0, *node1, *node2, *node3;

    node0 = malloc(sizeof(CDlistNode));
    node1 = malloc(sizeof(CDlistNode));
    node2 = malloc(sizeof(CDlistNode));
    node3 = malloc(sizeof(CDlistNode));
    node0->num = 10;
    node1->num = 20;
    node2->num = 30;
    node3->num = 40;

    node0->next = node1;
    node0->prev = node3;
    node1->next = node2;
    node1->prev = node0;
    node2->next = node3;
    node2->prev = node1;
    node3->next = node0;
    node3->prev = node2;

    cl->head = node0;
    cl->tail = node3;

    printf("Danh sach lien ket: \n");
    printList(cl);
    printf("con tro cua head       : %p\n", cl->head);
    printf("con tro cua node0      : %p\n", node0);
    printf("con tro cua node0->next: %p\n", node0->next);
    printf("con tro cua node1      : %p\n", node1);
    printf("con tro cua node0->prev: %p\n", node0->prev);
    printf("con tro cua node3      : %p\n", node3);
    // printf("con tro cua node0->next->prev: %p\n", node0->next->prev);
    // printf("con tro cua node0->prev->next: %p\n", node0->prev->next);
    printf("node0 == cl->tail->next: %s\n", node0 == cl->tail->next ? "true" : "false");
    printf("node3 == cl->head->prev: %s\n", node3 == cl->head->prev ? "true" : "false");
    printf("gia tri cua node0->num: %d\n", node0->num);

    insertNode(cl, 1, 25);
    printf("Sau khi chen phan tu 25 vao vi tri 1:\n");
    printList(cl);

    removeNode(cl, 2);
    printf("Sau khi xoa phan tu tai vi tri 2:\n");
    printList(cl);

    printf("In danh sach lien ket 2 lan:\n"); 
    printLoop1(cl, 2);
    printLoop2(cl, 2);

}

void printList(CLinkedList* cl) {
    CDlistNode* p = cl->head;
    if (p == NULL) {
        printf("Danh sach lien ket rong\n");
        return;
    }
    do {
        printf("%d ", p->num);
        p = p->next;
    } while (p != cl->head);
    printf("\n");
}

CDlistNode* findNode(CLinkedList* cl, int i) {
    CDlistNode *cur = cl->head;
    if ((cl->head == NULL) || (i < 0)) {
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }
    do {
        if (i == 0) {
            return cur;
        }
        cur = cur->next;
        i--;
    } while (cur != cl->head);
    printf("Phan tu tim kiem khong ton tai");
    return NULL;
}

void insertNode(CLinkedList* cl, int index, int value) {
    CDlistNode *cur, *newNode;
    if (cl->head == NULL || index == 0) {
        newNode = malloc(sizeof(CDlistNode));
        newNode->num = value;
        if (cl->head == NULL) {
            cl->head = newNode;
            cl->tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            newNode->next = cl->head;
            newNode->prev = cl->tail;
            cl->tail->next = newNode;
            cl->head->prev = newNode;
            cl->head = newNode;
        }
    } else if ((cur = findNode(cl, index - 1)) != NULL) {
        newNode = malloc(sizeof(CDlistNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next->prev = newNode;
        cur->next = newNode;
        newNode->prev = cur;
    } else {
        printf("Khong the chen phan tu moi tai chi so %d!\n", index);
    }
}

void removeNode(CLinkedList* cl, int index) {
    CDlistNode *cur, *pre;
    if (index == 0) {
        cur = cl->head;
        if (cl->head == cl->tail) {
            cl->head = NULL;
            cl->tail = NULL;
        } else {
            cl->head = cur->next;
            cl->tail->next = cl->head;
            cl->head->prev = cl->tail;
        }
        free(cur);
    } else {
        pre = findNode(cl, index - 1);
        cur = pre->next;
        pre->next = cur->next;
        cur->next->prev = pre;
        free(cur);
    }
}