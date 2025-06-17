#include<stdio.h>
#include<stdlib.h>

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
    node1->next = NULL ;
    head = node0;
}



void printList(ListNode *head) {
    ListNode *p = head;
    while (p != NULL) {
        printf("%d ", p->num);
        p = p->next;
    }
}

ListNode* findNode(ListNode *head, int i){
    ListNode *cur = head;
    if ((head == NULL)|| (i<0)){
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;       
    }
    while (i> 0){
        cur = cur->next;
        i--;
        if (cur == NULL){
            printf("Phan tu tim kiem khong ton tai");
            return NULL;
        }   
    }
    return cur;
}

void insertNode(ListNode **pHead, int index, int value){
    ListNode *cur, *newNode;
    if (*pHead == NULL || index == 0 ){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }
    else if ((cur = findNode( *pHead, index - 1 )) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next ;
        cur->next = newNode ;
    } else printf("can not insert the new item at index %d!\n", index);
}

void removeNode(ListNode **ptrHead, int index){
    ListNode *cur, *pre;
    if (index == 0 ) {
        cur = *ptrHead ;
        *ptrHead = cur->next ;
        free(cur);
    } else {
        pre = findNode( *ptrHead , index - 1);
        cur = pre->next ;
        pre->next = cur->next ;
        free(cur);
    }
}




