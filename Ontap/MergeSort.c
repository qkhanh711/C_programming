#include<stdio.h>
#include<stdlib.h>


int Merge(int arr[], int left, int mid, int right){
    int temp[mid-left - 1];
    int i = 0,  u = left,  v = mid + 1;

    for (i = 0; i< mid - left + 1; i++){
        temp[i] = arr[left + i];
    }
    i = 0;
    while (i <= mid - left){
        if (v <= right && arr[v] < temp[i]){
            arr[u] = arr[v];
            u++;
            v++;
        } else {
            arr[u] = temp[i];
            u++;
            i++;
        }
    }
}


int MergeSort(int arr[], int left, int right){
    if (right <= left) {
        return 0;
    }
    int mid = (right + left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
    
}

int main(){
    int arr[] = {42, 23, 74, 11, 65, 58, 96};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    MergeSort(arr, 0, n - 1);
    
    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
