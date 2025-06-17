#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct market {
    char item[1000];
    int cost;
    // int temp;
} Market;

void selection_sort(int k[], int n) {
    int i, j, m, x;
    for (i = 0; i < n; i++) {
        m = i;
        for (j = i + 1; j < n; j++)
            if (k[j] < k[m]) {
                m = j;
            }
        if (m != i) {
            x = k[i];
            k[i] = k[m];
            k[m] = x;
        }
    }
}

int main(void){
    FILE *inputFile = fopen("INPUT.txt", "r");
    FILE *outputFile = fopen("OUTPUT.txt", "w");
    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Khong the mo file\n");
        return 1;
    }
    
    int N;
    fscanf(inputFile, "%d", &N);

    Market *mar = malloc(N * sizeof(Market));
    printf("\n");

    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%s %d", mar[i].item, &mar[i].cost);
        printf("%s %d\n", mar[i].item, mar[i].cost);
        // mar[i].temp = i;
    }

    int *k = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        k[i] = mar[i].cost;
    }
    selection_sort(k, N);
    printf("\n");    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (k[i] == mar[j].cost) {
                printf("%s %d\n", mar[j].item, mar[j].cost);
                fprintf(outputFile, "%s\n", mar[j].item);
                break;
            }
        }
    }



    fclose(inputFile);
    fclose(outputFile);

}