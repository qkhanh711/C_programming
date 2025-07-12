#include<stdio.h>
#include<stdlib.h>


typedef struct _item{
    int time;
    char ID[20];
    int prioritize;
} Item;

int main(){
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(input_file, "%d", &n);

    Item items[n];
    for (int i = 0; i < n; i++) {
        fscanf(input_file,"%s %d %d", items[i].ID, &items[i].time, &items[i].prioritize);
        printf("Item %d: ID = %s, Time = %d, Prioritize = %d\n", i + 1, items[i].ID, items[i].time, items[i].prioritize);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].prioritize < items[j].prioritize || 
                (items[i].prioritize == items[j].prioritize && items[i].time > items[j].time)) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%s %d %d\n", items[i].ID, items[i].time, items[i].prioritize);
    }
    fclose(input_file);
    fclose(output_file);
}