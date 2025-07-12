#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[], int n, int x){
    int left = 0,  right = n - 1,  mid;
    while(left<= right){
        mid = (left+right) / 2;
        if(arr[mid == x]){
            return mid;
        }
        else if (arr[mid]<x){
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = BinarySearch(arr, n, x);
    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}