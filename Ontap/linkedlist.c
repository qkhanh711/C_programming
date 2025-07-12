#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int num;
    struct _node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

void print_ll(LinkedList *ll) {
    Node *curr = ll->head;  
    while (curr != NULL) {
        printf("%d ", curr->num);
        curr = curr->next; 
    }
    printf("\n");
}

Node* findNode(LinkedList *ll, int index) {
    Node *cur = ll->head;
    while (index > 0 && cur != NULL) {
        cur = cur->next;
        index--;
    }
    return cur; 
}

void insertNode(LinkedList *ll, int value, int index) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return 0; 
    newNode->num = value;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = ll->head;
        ll->head = newNode;
        return 1;
    }

    Node *cur = findNode(ll, index - 1);
    if (cur == NULL) return 0; 

    newNode->next = cur->next;
    cur->next = newNode;
    return 1;
}

void removeNode(LinkedList *ll, int index) {
    if (ll->head == NULL) return 0;

    Node *cur;
    if (index == 0) {
        cur = ll->head;
        ll->head = ll->head->next;
        free(cur);
        // return 1;
    }

    Node *prev = findNode(ll, index - 1);
    if (prev == NULL || prev->next == NULL) return 0;

    cur = prev->next;
    prev->next = cur->next;
    free(cur);
    // return 1;
}

int main() {
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    ll->head = NULL;

    insertNode(ll, 10, 0); 
    insertNode(ll, 20, 1); 
    insertNode(ll, 15, 1); 
    print_ll(ll); 

    removeNode(ll, 1); 
    print_ll(ll); 

    removeNode(ll, 0); 
    print_ll(ll); 

    removeNode(ll, 0); 
    print_ll(ll); 

    free(ll);
    return 0;
}
