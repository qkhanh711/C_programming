#include <stdio.h>

#define SIZE 7
int table[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1; // -1 nghĩa là ô trống
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int idx = hash(key);
    int originalIdx = idx;

    while (table[idx] != -1) {
        idx = (idx + 1) % SIZE;
        printf("Xung đột tại vị trí %d, thử vị trí %d\n", originalIdx, idx);
        if (idx == originalIdx) {
            printf("Bảng đầy, không thể chèn %d\n", key);
            return;
        }
    }
    table[idx] = key;
    printf("Đã chèn %d vào vị trí %d\n", key, idx);
}

void printTable() {
    printf("Bảng băm:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("[%d] : ___\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
}

int main() {
    int keys[] = {11, 13, 20, 14};
    int n = sizeof(keys)/sizeof(keys[0]);

    initTable();
    for (int i = 0; i < n; i++)
        insert(keys[i]);

    printTable();
    return 0;
}
