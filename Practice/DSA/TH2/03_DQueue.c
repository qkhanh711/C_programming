#include<stdio.h>
#include<stdlib.h>

typedef struct _dlistnode{
    int num;
    struct _dlistnode *next;
    struct _dlistnode *prev;
} DListNode;

typedef struct Deque {
    DListNode* head;
    DListNode* tail;
} Deque;

// 1) Hoàn thiện hàm tạo nút mới
DListNode* createNode(int data) {
    DListNode* newNode = (DListNode*) malloc(sizeof(DListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->num = data ;
    newNode->next = NULL ;
    newNode->prev = NULL ;
    return newNode;
}
// 2) Hoàn thiện hàm khởi tạo hàng đợi hai đầu
Deque* createDeque() {
    Deque* deque = (Deque*)malloc( sizeof(Deque));
    if (deque == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
    }
    deque->head = NULL; 
    deque->tail = NULL;
    return deque;
}
// 3) Hoàn thiện hàm kiểm tra hàng đợi hai đầu có rống không
int isEmpty(Deque* deque) {
    return deque->head == NULL ;
}
// 4) Hoàn thiện hàm liệt kê các phần từ trong hàng đợi hai đầu
void printDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    DListNode* current = deque->head;
    while (current != NULL) {
        printf("%d ", current->num );
        current = current->next ;
    }
    printf("\n");
}
// 5) Hoàn thiện hàm chèn một phần tử vào đầu hàng đợi hai đầu
void pushFront(Deque* deque, int data) {
    DListNode* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->head = newNode; 
        deque->tail = newNode;
    } else {
    newNode->next = deque->head;
    deque->head->prev = newNode;
    deque->head = newNode;
    }
}
// 6) Hoàn thiện hàm chèn một phần tử vào cuối hàng đợi hai đầu
void pushRear(Deque* deque, int data) {
    DListNode* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->head = newNode;
        deque->tail = newNode;
    } else {
        newNode->prev = deque->tail ;
        deque->tail->next = newNode ;
        deque->tail = newNode ;
    }
}
// 7) Hoàn thiện hàm lấy một phần tử ở đầu hàng đợi hai đầu
int popFront(Deque* deque) {
    if (isEmpty(deque)) {
    printf("Deque is empty.\n");
    return EXIT_FAILURE;
    }
    DListNode* frontNode = deque->head;
    int data = frontNode->num;
    deque->head = frontNode->next;
    if (deque->head != NULL) {
    deque->head->prev = NULL ;
    } else {
    deque->tail = NULL ;
    }
    free(frontNode);
    return data;
}
// 8) Hoàn thiện hàm lấy một phần tử ở cuối hàng đợi hai đầu
int popRear(Deque* deque) {
    if (isEmpty(deque)) {
    printf("Deque is empty.\n");
    return EXIT_FAILURE;
    }
    DListNode* rearNode = deque->tail;
    int data = rearNode->num;
    deque->tail = rearNode->prev;
    if (deque->tail != NULL) {
    deque->tail->next = NULL ;
    } else {
    deque->head = NULL ;
    }
    free( rearNode );
    return data;
}
// 9) Hoàn thiện hàm xem giá trị của phần tử ở đầu hàng đợi hai đầu
int peekFront(Deque* deque) {
    if (isEmpty(deque)) {
    printf("Deque is empty.\n");
    return EXIT_FAILURE;
    }
    return deque->head->num ;
}
// 10) Hoàn thiện hàm xem giá trị của phần tử ở cuối hàng đợi hai đầu
int peekRear(Deque* deque) {
    if (isEmpty(deque)) {
    printf("Deque is empty.\n");
    return EXIT_FAILURE;
    }
    return deque->tail->num ;
}

int main(){
    Deque* deque = createDeque();
    if (deque == NULL) {
        return EXIT_FAILURE;
    }
    pushFront(deque, 10);
    pushRear(deque, 20);
    pushFront(deque, 5);
    pushRear(deque, 30);
    
    printf("Deque after pushing elements: ");
    printDeque(deque);
    
    printf("Popped from front: %d\n", popFront(deque));
    printf("Popped from rear: %d\n", popRear(deque));
    
    printf("Deque after popping elements: ");
    printDeque(deque);
    
    printf("Peek front: %d\n", peekFront(deque));
    printf("Peek rear: %d\n", peekRear(deque));
    
    free(deque);
    return 0;
}