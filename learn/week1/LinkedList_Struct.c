#include<stdio.h>


typedef struct ListNode{
    int num;
    struct ListNode *next;
} ListNode;

void displayList(ListNode *head){
    ListNode *current = head;
    while (current != NULL){
        printf("%d ", current -> num);
        current = current -> next;
    }
    printf("\n");
}



int main(){
    // ListNode *newNode, *Node1, *Node2;
    // newNode = malloc(sizeof(ListNode));
    // newNode -> num = 5;
    // Node1 = malloc(sizeof(ListNode));
    // Node1 -> num = 10;
    // Node2 = malloc(sizeof(ListNode));
    // Node2 -> num = 15;
    
    
    // newNode -> next = Node2;
    // Node1 -> next = Node2;
    // Node2 -> next = NULL;

    // displayList(newNode);
    // displayList(Node1);
    // displayList(Node2);
    // // Free the allocated memory
    // free(newNode);
    // free(Node1);
    // free(Node2);

    printf("Input number of Nodes:" );
    int n;
    scanf("%d", &n);
    ListNode *head = NULL, *newNode;
    newNode = malloc(sizeof(ListNode));
    head = newNode;
    for (int i = 0; i< n; i++){
        scanf("%d", newNode -> num);
        newNode -> next = malloc(sizeof(ListNode));
        newNode = newNode -> next;
    }
    scanf("%d", newNode -> num);
    newNode -> next = NULL;
    displayList(head);
    // Free the allocated memory   
    ListNode *current = head;
    ListNode *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL; // Set head to NULL after freeing the list
    // Display the list again to confirm it's empty


    return 0;
}