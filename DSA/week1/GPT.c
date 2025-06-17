#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;

/* prototypes */
void printList(ListNode *head);
ListNode* findNode(ListNode *head, int i);
void insertNode(ListNode **pHead, int index, int value);
void removeNode(ListNode **ptrHead, int index);

/* -------------------  HÀM MAIN KIỂM THỬ  ------------------- */
int main(void)
{
    /* 1. tạo danh sách ban đầu: 20 -> 30                        */
    ListNode *node0 = malloc(sizeof(ListNode));
    ListNode *node1 = malloc(sizeof(ListNode));
    node0->num = 20;    node0->next = node1;
    node1->num = 30;    node1->next = NULL;
    ListNode *head = node0;

    puts("== Danh sách ban đầu ==");
    printList(head);               /* 20 30 */

    /* 2. chèn (insertNode)                                      */
    puts("\n== Thử chèn ==");
    insertNode(&head, 0, 10);      /* chèn đầu               → 10 20 30  */
    insertNode(&head, 2, 25);      /* chèn giữa              → 10 20 25 30 */
    insertNode(&head, 4, 40);      /* chèn cuối (index==len) → 10 20 25 30 40 */
    insertNode(&head, 99, 50);     /* chèn lỗi               */
    printList(head);

    /* 3. tìm (findNode)                                         */
    puts("\n== Thử findNode ==");
    for (int i = 0; i < 6; ++i) {
        ListNode *p = findNode(head, i);
        if (p) printf("Node %d = %d\n", i, p->num);
    }

    /* 4. xoá (removeNode)                                       */
    puts("\n== Thử removeNode ==");
    removeNode(&head, 0);          /* xoá đầu       → 20 25 30 40 */
    removeNode(&head, 2);          /* xoá giữa      → 20 25 40    */
    removeNode(&head, 10);         /* xoá lỗi       */
    printList(head);

    /* 5. giải phóng bộ nhớ                                      */
    while (head) {
        ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}

/* -------------------  ĐỊNH NGHĨA HÀM TIỆN ÍCH --------------- */
void printList(ListNode *head)
{
    if (!head) { puts("Danh sach lien ket khong co phan tu nao"); return; }
    for (ListNode *cur = head; cur; cur = cur->next) printf("%d ", cur->num);
    putchar('\n');
}

ListNode *findNode(ListNode *head, int i)
{
    if (!head || i < 0) { puts("Danh sach rong hoac index khong hop le"); return NULL; }
    while (i-- && head) head = head->next;
    if (!head) { puts("Phan tu tim kiem khong ton tai"); return NULL; }
    return head;
}

void insertNode(ListNode **pHead, int index, int value)
{
    ListNode *newNode, *prev;
    if (*pHead == NULL || index == 0) {          /* chèn đầu */
        newNode       = malloc(sizeof(ListNode));
        newNode->num  = value;
        newNode->next = *pHead;
        *pHead        = newNode;
    }
    else if ((prev = findNode(*pHead, index-1)) != NULL) {
        newNode       = malloc(sizeof(ListNode));
        newNode->num  = value;
        newNode->next = prev->next;
        prev->next    = newNode;
    }
    else
        printf("Can not insert the new item at index %d!\n", index);
}

void removeNode(ListNode **ptrHead, int index)
{
    if (!*ptrHead) { puts("Danh sach rong"); return; }

    ListNode *cur, *prev;
    if (index == 0) {                           /* xoá đầu */
        cur       = *ptrHead;
        *ptrHead  = cur->next;
        free(cur);
    } else {
        prev = findNode(*ptrHead, index-1);
        if (!prev || !prev->next) {
            printf("Khong the xoa phan tu tai index %d!\n", index);
            return;
        }
        cur        = prev->next;
        prev->next = cur->next;
        free(cur);
    }
}
