#include <stdio.h>

int add(int a, int b);

int main() {
   printf("5 + 3 = ",add(5, 3));
   return 0;
}


int add(int a, int b) {
   return a + b;
}
