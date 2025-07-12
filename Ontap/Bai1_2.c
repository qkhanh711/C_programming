#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int num;
    struct _node *next;
} Node;

typedef struct __linkedlistlist {
    Node *head;
} LinkedList;

void insert(LinkedList *ll, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = value;
    newNode->next = ll->head;
    ll->head = newNode;
}

void init_ll(LinkedList *ll) {
    ll->head = NULL;
}

void print_list(LinkedList *ll){
    Node *curr = (Node *)malloc(sizeof(Node));
    curr = ll->head;
    while(curr->next != NULL){
        printf("%d ", curr->num);
        curr = curr->next;
    }
    printf("%d", curr->num);  
}


void findNode(LinkedList *ll, int value){
    Node *curr = ll->head;
    Node *removed_node = NULL;
    while (curr != NULL) {
        if (curr->num == value) {
            removed_node = curr->next;
            curr->next = removed_node->next;
            free(removed_node);
            return;
        }
        curr = curr->next;
    }
}
    

int main(){
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    LinkedList ll;
    init_ll(&ll);

    int n, m;
    fscanf(input_file, "%d %d", &n, &m);
    printf("n = %d\n", n);
    int arr_n[1000];
    for (int i = 0; i< n; i++){
        fscanf(input_file, "%d", &arr_n[i]);
        insert(&ll, arr_n[i]);
        printf("arr[%d] = %d\n", i, arr_n[i]);
    }
    printf("Linked List: ");
    print_list(&ll);
    printf("\n");
    int arr_m[1000];
    for (int i = 0; i< m; i++){
        fscanf(input_file, "%d", &arr_m[i]);
        printf("arr_m[%d] = %d\n", i, arr_m[i]);
    }

    for (int i = 0; i < m; i++) {
        findNode(&ll, arr_m[i]);
    }
    printf("Linked List after removing elements: ");
    print_list(&ll);
    printf("\n");

    Node *curr = ll.head;
    while (curr != NULL) {
        fprintf(output_file, "%d ", curr->num);
        curr = curr->next;
    }



}