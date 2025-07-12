#include <stdio.h>

int binarySearchInsert(int arr[], int n, int target) {
    int left = 0, right = n - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            left = mid +1;
        } else {
            right = mid;
        }
        
    }
    return left;
    
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("OUTPUT.TXT", "w");

    if (!fin || !fout) {
        printf("Lỗi mở file.\n");
        return 1;
    }

    int n, target;
    fscanf(fin, "%d %d", &n, &target);

    int arr[1000];  
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
        printf("arr[%d] = %d\n", i, arr[i]); // Uncomment for debugging
    }

    int result = binarySearchInsert(arr, n, target);
    fprintf(fout, "%d\n", result);

    fclose(fin);
    fclose(fout);
    return 0;
}
