#include<stdio.h>
#include<string.h>
#include<ctype.h>

int Bai1(){
    int arr[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", 3*arr[2] - arr[0] - arr[1]);
    return 0;
}

int maxArray(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int Bai3(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // int max = maxArray(arr, n);
    // printf("%d", max);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    if (count == 0) {
        printf("0");
    }
    else {
        printf("%d\n", count);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}

int Bai5() {
    char a, b;
    scanf("%c %c", &a, &b);
    int count = 0;
    while (b < a) {
        count++;
        b++;
    }
    printf(count > 0 ? "%d" : "0", count-1);
    return 0;
}

int Bai6(){
    int n;
    scanf("%d", &n);
    int a,b,c;
    while (n >0) {
        scanf("%d %d %d", &a, &b, &c);
        if (a < b+c && b < a+c && c < a+b) {
            printf("YES\n");
            // break;
        } else {
            printf("NO\n");
        }
        n--;
    }
    return 0;
}


int Bai7() {
    char str[100000];
    scanf("%[^\n]", str);
    getchar();
    int countNumber = 0, countDigit = 0;
    int i = 0;
    while (str[i] != NULL) {
        if (isdigit(str[i])) countDigit++; 
        if (isalpha(str[i])) countNumber++;
        i++;
    }
    printf("%d %d", countNumber, countDigit);
    return 0;
}

int Bai8(){
    char a = 'a';
    char Z = 'Z';
    char A = 'A';
    // printf("%d %d %d", a, Z, A);
    char str[100000];
    scanf("%s", &str);
    getchar();
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] + ('A' - 'a');
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - ('A' - 'a');
        }
        i++;
    }
    printf("%s", str);
    return 0;
}

int main() {
    char ten[50], quequan[50];
    int msv, tuoi;
    scanf("%[^\n] \n %d \n %d \n %[^\n]", ten, &msv, &tuoi, quequan);
    printf("Ho ten sinh vien: %s\n", ten);
    printf("Ma so sinh vien: %d\n", msv);
    printf("Tuoi sinh vien: %d\n", tuoi);
    printf("Que quan: %s\n", quequan);
}


