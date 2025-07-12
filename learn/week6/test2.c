#include <stdio.h>
#include <string.h>

void replaceSubstr(char *B, const char *A) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    char result[1000];
    int i = 0, k = 0;

    while (i <= lenB - lenA) {
        // So sánh chuỗi con bắt đầu tại B[i]
        if (strncmp(&B[i], A, lenA) == 0) {
            // Ghi vào result các dấu *
            for (int j = 0; j < lenA; j++) {
                result[k++] = '*';
            }
            i += lenA;
        } else {
            result[k++] = B[i++];
        }
    }

    // Sao chép phần còn lại của B (nếu có)
    while (i < lenB) {
        result[k++] = B[i++];
    }

    result[k] = '\0'; // Kết thúc chuỗi

    printf("%s\n", result);
}

int main() {
    char A[100], B[1000];
    scanf("%s", A);
    scanf("%s", B);
    replaceSubstr(B, A);
    return 0;
}
