# include<stdio.h>
# include<stdlib.h>
# include<math.h>

// Bài 1: Bài tập Cài đặt CTDL ngăn xếp
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

// Cho khai báo kiểu của một ngăn xếp như sau:
typedef struct _stack {
    LinkedList ll;
} Stack;

// Cho khai báo của các hàm thực hiện các thao tác trên danh sách liên kết (đã cài đặt trong bài thực hành về danh sách liên kết) như sau:
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
// Hiện ra màn hình giá trị của các phần tử trong danh sách liên kết trỏ bởi head. Nếu danh sách liên kết không có phần tử nào thì hiện thông báo "Danh sach lien ket khong co phan tu nao".
ListNode* findNode(ListNode *head, int i) {
    ListNode *current = head;
    int count = 0;
    while ( current != NULL && count < i) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Khong tim thay node thu %d\n", i);
        return NULL;
    }
    return current;
}
// Trả về địa chỉ của node thứ i trong danh sách liên kết trỏ bởi head. Node đầu tiên của danh sách liên kết là node thứ 0.
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
// Chèn một nút có giá trị value vào vị trí index trong danh sách liên kết trỏ bởi *pHead.
void removeNode(ListNode **ptrHead, int index) {
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

// Cho khai báo của các hàm thực hiện các thao tác trên ngăn xếp như sau:
void push(Stack *s, int item);

// void push(Stack *s, int item) {
//     insertNode(&(s->ll.head), 0, item);
//     s->ll.size++;
// }
// Đưa vào đỉnh ngăn xếp một phần tử có giá trị item.

int pop(Stack *s);

// int pop(Stack *s) {
//     int item;
//     // if (s->ll.head != NULL)
//     if (s->ll.size > 0) {
//         item = s->ll.head->num;
//         removeNode(&(s->ll.head), 0);
//         s->ll.size--;
//         return item;
//     }
//     else {
//         printf("Ngan xep rong");
//         return -1; // Hoặc một giá trị khác để chỉ ra ngăn xếp rỗng
//     }
// } 
// Lấy một phần tử ra khỏi đỉnh ngăn xếp. Giá trị trả về của hàm là giá trị của phần tử lấy ra.

int peek(Stack *s);

// int peek(Stack *s) {
//     if (s->ll.head != NULL)
//         return s->ll.head->num;
//     else {
//         printf("Ngan xep rong");
//         return -1; // Hoặc một giá trị khác để chỉ ra ngăn xếp rỗng
//     }
// }

// Trả về giá trị của nút ở đỉnh ngăn xếp, không tạo sự thay đổi gì trong ngăn xếp.

int isEmptyStack(Stack *s);

// int isEmptyStack(Stack *s) {
//     if (s->ll.size == 0) return 1;
//     return 0;
// }
// Trả về 1 nếu ngăn xếp rỗng, trả về 0 nếu ngăn xếp không rỗng.

// 1) Khai báo các cấu trúc dữ liệu và các hàm đã cho.

// 2) Hoàn thiện các hàm thao tác trên danh sách liên kết trong bài thực hành về danh sách liên kết.

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

    while (!isEmptyStack(s)) {
        printf("Lay phan tu ra khoi ngan xep: %d\n", pop(s));
    }
    printf("Ngan xep da rong\n");
    free(s);
    return 0;


}
// 3) Hoàn thiện đoạn chương trình dưới đây trong hàm main() để tạo một ngăn xếp rỗng:
//     Stack *s = malloc( ___ );
//     s->ll.size = ___ ;
//     s->ll.head= ___ ;

// 4) Trong hàm main(), dùng hàm printList() để đưa ra danh sách các phần tử trong ngăn xếp.

// 5) Hoàn thiện hàm push()
void push(Stack *s, int item ) {
    insertNode( &(s->ll.head), 0, item);
    s->ll.size += 1;
}

// 6) Hoàn thiện hàm pop()
int pop(Stack *s) {
    int item;
    if (!isEmptyStack(s)) {
        item = s->ll.head->num; ;
        removeNode( &(s->ll.head), 0 );
        (s->ll).size -= 1;
        return item ;
    }
    else { 
        printf("Ngan xep rong\n");
        return -1;
    }    
}

// 7) Hoàn thiện hàm peek()
int peek(Stack *s) {
    if ( !isEmptyStack(s) )
        return s->ll.head->num;
    else { 
        printf("Ngan xep rong\n");
        return -1;
    }
}

// 8) Hoàn thiện hàm isEmptyStack()
int isEmptyStack(Stack *s) {
    if ( s->ll.size== 0) return 1;
    return 0;
}

// 9) Viết hàm main() để kiểm tra kết quả khi gọi các hàm trên.

 

