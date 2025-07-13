#include <stdio.h>

#define SIZE 7
#define EMPTY -1

int hash(int key) {
    return key % SIZE;
}

void insert(int table[], int key) {
    int index = hash(key);
    int start = index;

    // Linear probing
    while (table[index] != EMPTY) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Hash table full, cannot insert %d\n", key);
            return;
        }
    }

    table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void printTable(int table[]) {
    printf("Final hash table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == EMPTY)
            printf("b[%d] = _\n", i);
        else
            printf("b[%d] = %d\n", i, table[i]);
    }
}

int main() {
    int table[SIZE];
    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;

    int keys[] = {11, 13, 20, 14};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(table, keys[i]);
    }

    printTable(table);
    return 0;
}
