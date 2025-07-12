#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _point {
    int x;
    int y;
} Point;

// typedef struct Node {
//     Point point;
//     struct Node *next;
// } Node;

// typedef struct LinkedList {
//     Node *head;
// } LinkedList;

// LinkedList* create_list() {
//     LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
//     list->head = NULL;
//     return list;
// }

// void insert(LinkedList *list, Point point) {
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     new_node->point = point;
//     new_node->next = list->head;
//     list->head = new_node;
// }


int lenght(Point p) {
    return p.x * p.x + p.y * p.y;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    int n;
    Point points[1000];

    // LinkedList *ll = create_list();

    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fscanf(input_file, "%d", &n);
    printf("n = %d\n", n);


    for (int i = 0; i< n; i++){
        for (int j = 0; j < i; j++) {
            if (lenght(points[i]) < lenght(points[j])) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    } 
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d %d", &points[i].x, &points[i].y);
        fprintf(output_file, "%d %d\n", points[i].x, points[i].y);
        // insert(ll, points[i]);
        printf("Point %d: (%d, %d)\n", i, points[i].x, points[i].y);
    }

}