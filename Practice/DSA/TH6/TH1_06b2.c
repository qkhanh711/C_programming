#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;

void printList(ListNode *head) {
    ListNode *cur = head;
    while (cur != NULL ) {
        printf("%d", cur->num);
        if (cur->next != NULL)
            printf("->");
        cur = cur->next;
    }
}

void insertAtTheBegin(ListNode **phead, int data) {
    ListNode *ptr1 = malloc(sizeof(ListNode));
    ptr1->num = data;
    ptr1->next = *phead;
    *phead = ptr1;
}

void selectionSort(ListNode *head){
    ListNode *temp = head;
    while (temp) {
        ListNode *min = temp;
        ListNode *r = temp->next;

        while(r) {
            if (min->num > r->num) {
                min = r;
            }
            r = r->next;
        }
        int x = temp->num;
        temp->num = min->num;
        min->num = x;
        temp = temp->next;
    }
}

void bubbleSort(ListNode *head) {
    int swapped, i;
    ListNode *ptr1;
    ListNode *lptr = NULL;

    if (head == NULL) {
        return;
    }
    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr){
            if (ptr1->num > ptr1->next->num) {
                int temp = ptr1->num;
                ptr1->num = ptr1->next->num;
                ptr1->next->num = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

    } while (swapped);
    
}

void insertionSort(ListNode **phead){
    ListNode *sorted = NULL;
    ListNode *current = *phead;

    while (current != NULL) {
        ListNode *next = current->next;
        if (sorted == NULL || sorted->num >= current->num) {
            current->next = sorted;
            sorted = current;
        }
        else {
            ListNode *tl = sorted;

            while (tl->next != NULL && tl->next->num < current->num) {
                tl = tl->next;
            }
            current->next = tl->next;
            tl->next = current;
        }
        current = next;
    }
    *phead = sorted;
}

int main(void) {
    int arr[] = { 10, 55, 33, 66, 99, 88 };
    int i;
    ListNode *head = NULL;
    for (i = 0; i < 6; i++)
        insertAtTheBegin(&head, arr[i]);
    
    printf("\n Linked list before sorting ");
    printList(head);

    bubbleSort(head);
    selectionSort(head);
    insertionSort(&head);
    
    printf("\n Linked list after sorting ");
    printList(head);
    return 0;
}

