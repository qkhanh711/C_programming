#include<stdio.h>
#include<stdlib.h>

int Bai1(){
    long long n, num;
    scanf("%lld %lld", &n, &num);   
    printf("%lld", n* num);
    return 0;
}

int Bai2(){
    char c;
    scanf("%c", &c);
    printf("%c", (c - 'A' + 'a') - 1 == 'z' ? 'a' : (c - 'A' + 'a') - 1);
    return 0;
}

int Bai3(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a < b + c && b < a + c && c < a + b) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}

int Bai4(){
    int n, count = 0;
    int arr[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > 0) {
            count++;
        }
    }
    if (count == 0) {
        printf("Day so khong co phan tu duong\n");
        return 0;
    }
    else {
    printf("%d\n", count);
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            printf("%d ", arr[i]);
        }
    }
    }
    return 0;
}

int Bai5(){
    char str[100000];
    scanf("%[^\n]", str);
    getchar();
    int i = 0, count = 0;
    while (str[i] != NULL){
        if (str[i] == ' '){
            count++;
        }
        i++;
    }
    printf("%d", count + 1);
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int id[8];
        char name[30];
        float GPA;   
        // scanf("%d\n%[^\n]\n%f", &id[i], name, &GPA);
        scanf("%d", &id[i]);
        // scanf("%s", name);
        // gets(name);
        scanf("%[^\n]s",name);
        getchar();
        scanf("%f", &GPA);
        if (id[i] / 1000000 == 24 && GPA > 2.0 && GPA < 2.5) {
            printf("%d %s %.2f\n", id[i], name, GPA);
            count++;
        }
    }
    printf("%d", count);
    // do
    // {
    //     /* code */
    // } while (condition);

    // switch (expression)
    // {
    // case constant expression:
    //     /* code */
    //     break;
    
    // default:
    //     break;
    // }

    // do      
    
}