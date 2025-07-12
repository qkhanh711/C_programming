
#include<stdio.h>
#include<stdlib.h>

typedef struct _lisnode {
    int num;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
    ListNode *head;
    int size;
} LinkedList;

typedef struct _queue {
    LinkedList ll;
} Queue;

void printList(ListNode *head);

void printList(ListNode *head){
    printf("Danh sach lien ket: \n");
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

ListNode* findNode(ListNode *head, int i);

ListNode* findNode(ListNode *head, int i){
    ListNode *current = head;
    while (i > 0 && head != NULL){
        current = current->next;
        i--;
    }
    if (current == NULL){
        printf("Khong tim thay node thu %d\n", i);
        return NULL;
    }
    return current;
}


void insertNode(ListNode **pHead, int index, int value);

void insertNode(ListNode **pHead, int index, int value){
    ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->num = value;
    newNode->next = NULL;
    if (index == 0){
        newNode->next = *pHead;
        *pHead = newNode; 
    } else {
        ListNode *current = *pHead;
        for (int i = 0; i< index - 1; i++){
            current = current->next;
        }
        if (current == NULL){
            printf("Khong tim thay node thu %d\n", index);
            return;
        } 
        newNode->next = current->next;
        current->next = newNode; 
    }
}

void removeNode(ListNode **ptrHead, int index);

void removeNode(ListNode **ptrHead, int index) {
    if (*ptrHead == NULL) {
        printf("Khong the xoa node tai vi tri %d\n", index);
        return;
    }
    if (index == 0) {
        ListNode *current = *ptrHead;
        *ptrHead = current->next;
        free(current);
    } else {
        ListNode *current = *ptrHead;
        ListNode *prev = findNode(*ptrHead, index - 1);
        if (prev == NULL || prev->next == NULL) {
            printf("Khong tim thay node thu %d\n", index);
            return;
        }
        // for (int i = 0; i < index && current != NULL; i++) {
        //     prev = current;
        //     current = current->next;
        // }
        // if (current == NULL) {
        //     printf("Khong tim thay node thu %d\n", index);
        //     return;
        // }
        current = prev->next;
        prev->next = current->next;
        free(current);

        // ListNode *prev = findNode(*ptrHead, index - 1);
        // if (prev == NULL || prev->next == NULL) {
        //     printf("Khong tim thay node thu %d\n", index);
        //     return;
        // }
        // ListNode *current = prev->next;
        // prev->next = current->next;
        // free(current);

    }
}

void enqueue(Queue *q, int item);

int dequeue(Queue *q);

int peek(Queue *q);

int isEmptyQueue(Queue *q);

int main(){
    Queue *q = malloc(sizeof(Queue));

    q->ll.size = 0;
    q->ll.head = NULL;

    printList(q->ll.head);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printf("Hang doi sau khi enqueue 3 phan tu: \n");
    printList(q->ll.head);
    
    printf("Phan tu o dau hang doi (peek): %d\n", peek(q));
    
    printf("Lay phan tu ra khoi hang doi: %d\n", dequeue(q));
    printf("Hang doi sau khi dequeue: ");
    printList(q->ll.head);
    
    printf("Lay phan tu ra khoi hang doi: %d\n", dequeue(q));
    printf("Lay phan tu ra khoi hang doi: %d\n", dequeue(q));
    printf("Lay phan tu ra khoi hang doi: %d\n", dequeue(q)); // nên báo lỗi
    
    free(q);
    return 0;


}


// 5) Hoàn thiện hàm enqueue()
void enqueue(Queue *q, int item) {
    insertNode( &(q->ll.head) , q->ll.size, item);
    q->ll.size +=  1;
}

// 6) Hoàn thiện hàm dequeue()
int dequeue(Queue *q) {
    int item;
        if (q->ll.head != NULL) {
        item = q->ll.head->num;
        removeNode( &(q->ll.head), 0 );
        (q->ll).size -= 1 ;
        return item;
    } else {
        printf("Hang doi rong");
        return 0;
    }
}

// 7) Hoàn thiện hàm peek()
int peek(Queue *q){
    if (q->ll.head != NULL)
        return q->ll.head->num;
    else {
        printf("Hang doi rong");
        return 0;
    }
}
// 8) Hoàn thiện hàm isEmptyQueue()
int isEmptyQueue(Queue *q){
    if ( q->ll.size == 0 ) return 1;
    return 0;
}