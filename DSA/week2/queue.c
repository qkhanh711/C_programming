#include <stdio.h>
#include <stdlib.h>

// Bài 2: Bài tập Cài đặt CTDL hàng đợi
// Cho khai báo kiểu của một nút trong danh sách liên kết như sau:
typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;

// Cho khai báo kiểu của một danh sách liên kết như sau:
typedef struct _linkedlist { 
    ListNode *head;
    int size;
} LinkedList;

// Cho khai báo kiểu của một hàng đợi như sau:
typedef struct _queue { 
    LinkedList ll;
} Queue;


// Cho khai báo của các hàm thực hiện các thao tác trên danh sách liên kết (đã cài đặt trong bài thực hành về danh sách liên kết) như sau:
void printList(ListNode *head);
// Hiện ra màn hình giá trị của các phần tử trong danh sách liên kết trỏ bởi head. Nếu danh sách liên kết không có phần tử nào thì hiện thông báo "Danh sach lien ket khong co phan tu nao".
void printList(ListNode *head) {
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
// Trả về địa chỉ của node thứ i trong danh sách liên kết trỏ bởi head. Node đầu tiên của danh sách liên kết là node thứ 0.
ListNode* findNode(ListNode *head, int i) {
    ListNode *current = head;
    int count = 0;
    while (current != NULL && count < i) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Khong tim thay node thu %d\n", i);
        return NULL;
    }
    return current;
}
void insertNode(ListNode **pHead, int index, int value);
// Chèn một nút có giá trị value vào vị trí index trong danh sách liên kết trỏ bởi *pHead.

void insertNode(ListNode **pHead, int index, int value) {
    ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->num = value;
    newNode->next = NULL;
    if (index == 0) {
        newNode->next = *pHead;
        *pHead = newNode;
    } else {
        ListNode *current = *pHead;
        for (int i = 0; i < index - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Khong the chen node tai vi tri %d\n", index);
            free(newNode);
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    } 
}


void removeNode(ListNode **ptrHead, int index);
void removeNode(ListNode **ptrHead, int index){
    if (*ptrHead == NULL) {
        printf("Khong the xoa node tai vi tri %d\n", index);
        return;
    }
    ListNode *current = *ptrHead;
    if (index == 0) {
        *ptrHead = current->next;
        free(current);
    } else {
        ListNode *prev = NULL;
        for (int i = 0; i < index && current != NULL; i++) {
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("Khong tim thay node thu %d\n", index);
            return;
        }
        prev->next = current->next;
        free(current);
    }
}
// Xóa nút ở vị trí index trong danh sách liên kết trỏ bởi *pHead.

// Cho khai báo của các hàm thực hiện các thao tác trên hàng đợi như sau:
void enqueue(Queue *q, int item);
// Đưa vào hàng đợi một phần tử có giá trị item.

int dequeue(Queue *q);
// Lấy một phần tử ra khỏi hàng đợi. Giá trị trả về của hàm là giá trị của phần tử lấy ra.

int peek(Queue *q);
// Trả về giá trị của nút ở đầu hàng đợi, không tạo sự thay đổi gì trong hàng đợi.

int isEmptyQueue(Queue *q);
// Trả về 1 nếu hàng đợi rỗng, trả về 0 nếu hàng đợi không rỗng.

// 1) Khai báo các cấu trúc dữ liệu và các hàm đã cho

// 2) Hoàn thiện các hàm thao tác trên danh sách liên kết trong bài thực hành về danh sách liên kết.

// 3) Hoàn thiện đoạn chương trình dưới đây trong hàm main() để tạo một hàng đợi rỗng:
//     Queue *q = malloc( ___ );
//     q->ll.size = ___ ;
//     q->ll.head= ___ ;

// 4) Trong hàm main(), dùng hàm printList() để đưa ra danh sách các phần tử trong hàng đợi.

// 5) Hoàn thiện hàm enqueue()
void enqueue(Queue *q, int item) {
    insertNode( &(q->ll.head), q->ll.size, item);
    q->ll.size++ ;
}

// 6) Hoàn thiện hàm dequeue()
int dequeue(Queue *q) {
    int item;
    if (q->ll.head != NULL) {
        item = q->ll.head->num;
        removeNode( &(q->ll.head), 0);
        (q->ll).size = -1;
        return item;
    }
    else {
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
    if  (  q->ll.size == 0) return 1;
    return 0;
}

// 9) Viết hàm main() để kiểm tra kết quả khi gọi các hàm trên.
int main () {
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