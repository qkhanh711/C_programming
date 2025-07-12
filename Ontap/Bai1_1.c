#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    int num;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList; 

LinkedList* create_list() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

// void insert(LinkedList *list, int num) {
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     new_node->num = num;
//     new_node->next = NULL;
//     printf("Inserting %d into the list\n", num);
//     if (list->head == NULL) {
//         list->head = new_node;
//     } else {
//         Node *current = list->head;
//         new_node->next = current->next;
//         current->next = new_node;

//     }
// }

void insert(LinkedList *list, int num) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->num = num;
    new_node->next = list->head;
    list->head = new_node;
}


int main(){
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    int n;
    int arr[1000];

    LinkedList *ll = create_list();

    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(input_file, "%d", &n);
    printf("n = %d\n", n);
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
        insert(ll, arr[i]);
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    Node *current = ll->head;
    while (current->next != NULL) {
        printf("%d ", current->num);
        fprintf(output_file, "%d ", current->num);
        current = current->next;
    }
    printf("%d\n", current->num); // Print the last element
    fprintf(output_file, "%d\n", current->num); // Print the last element
    fclose(input_file);
    fclose(output_file);
}