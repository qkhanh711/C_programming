# include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Bài 1: Cho khai báo kiểu của một nút trong danh sách liên kết như sau
typedef struct ListNode{
    int num;
    struct ListNode *next;
} ListNode;

//Cho khai báo của các hàm thực hiện các thao tác trên danh sách liên kết như sau   
void printList(ListNode *head);
// Hiện ra màn hình giá trị của các phần tử trong danh sách liên kết trỏ bởi head. Nếu danh sách liên kết không có phần tử nào thì hiện thông báo "Danh sach lien ket khong co phan tu nao".
ListNode* findNode(ListNode *head, int i);
// Trả về địa chỉ của node thứ i trong danh sách liên kết trỏ bởi head. Node đầu tiên của danh sách liên kết là node thứ 0.

void insertNode(ListNode **pHead, int index, int value);
// Chèn một nút có giá trị value vào vị trí index trong danh sách liên kết trỏ bởi *pHead.
// Neu khong dung con tro tro vao con tro se khong the truy van con tro o node dau tien
void insertNode_not_poiter(ListNode *head, int index, int value);

void check_insert_with_and_without_pointer(ListNode *head, int index, int value);

void removeNode(ListNode **pHead, int index);
// Xóa nút ở vị trí index trong danh sách liên kết trỏ bởi *pHead .

int main(){
    ListNode *node0, *node1, *head;
    node0 = malloc(sizeof(ListNode));
    node1 = malloc(sizeof(ListNode));
    node0->num = 20;
    node1->num = 30;
    node0->next = node1;
    node1->next = NULL;
    head = node0; 
    printf("Danh sach lien ket ban dau:\n");
    printList(head);
    printf("Phan tu tai vi tri 0 la: \n%d\n", findNode(head, 0)->num);


    insertNode(&head, 0, 10);                    
    printf("Danh sach lien ket sau khi chen phan tu 10 vao vi tri 0:\n");
    printList(head);
    
    insertNode_not_poiter(head, 0, 11);
    printf("Danh sach lien ket sau khi chen phan tu 11 vao vi tri 0:\n");
    printList(head);

    removeNode(&head, 1);
    printf("Danh sach lien ket sau khi xoa phan tu tai vi tri 1:\n");
    printList(head);

    insertNode(&head, 1, 10);
    printf("Danh sach lien ket sau khi chen phan tu 10 vao vi tri 1:\n");
    printList(head);

    insertNode(&head, 2, 20);
    printf("Danh sach lien ket sau khi chen phan tu 20 vao vi tri 2:\n");
    printList(head);
    
    printf("Danh sach lien ket sau khi chen phan tu 25 vao vi tri 0:\n");
    check_insert_with_and_without_pointer(head, 0, 25);


    printf("In danh sach lien ket \n");
    printList(head);

                         
}


void printList(ListNode *head){
    if (head == NULL){
        printf("Danh sach lien ket khong co phan tu nao\n");
        return;
    }
    ListNode *current = head;
    while (current != NULL){
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}


ListNode* findNode(ListNode *head, int i){
    ListNode *cur = head;
    if ((head == NULL) || (i < 0)) {
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }
    while (i > 0) {
        cur = cur->next; ;
        i = i - 1;
        if (cur == NULL) {
            printf("Phan tu tim kiem khong ton tai");
            return NULL;
        }
    }
    return cur;
}   


void insertNode(ListNode **pHead, int index, int value){
    ListNode *cur, *newNode;
    if (*pHead == NULL || index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }
    else if ((cur = findNode(*pHead, index - 1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    } else {
        printf("can not insert the new item at index %d!\n", index);
    }
}


void removeNode(ListNode **pHead, int index){
    ListNode *cur, *pre;
    if (index== 0){
        cur = *pHead;
        *pHead = (*pHead)->next;
        free(cur);
    }
    else{
        pre = findNode(*pHead, index - 1);
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
}


void insertNode_not_poiter(ListNode *head, int index, int value){
    ListNode *cur, *newNode;
    if (head == NULL || index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = head;
        head = newNode;
    }
    else if ((cur = findNode(head, index - 1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    } else {
        printf("can not insert the new item at index %d!\n", index);
    }
}


void check_insert_with_and_without_pointer(ListNode *pHead, int index, int value){
    printf("Insert with pointer:\n");
    insertNode(&pHead, index, value);
    printList(pHead);

    printf("Insert without pointer:\n");
    insertNode_not_poiter(pHead, index, value);
    printList(pHead);  
}