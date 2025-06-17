#include <stdio.h>
#include <stdlib.h>

int ex4Search()
{
    int i;
    printf("\nDUYET MANG: TIM KIEM GIA TRI\n");
    char myChar[5] = {'b', 'a', 'c', 'k', 's'};
    char searchChar;
    printf("Nhap vao ki tu can tim kiem: ");
    scanf("%c", searchChar);
    for (i = 0; i < 5; i++) {
        if (myChar[i] == searchChar){
            printf ("Tim thay ki tu %c tai vi tri %d\n", myChar[i], i);
            break;
        }
    }
}

int ex5FindMax1()
{
    int i;
    printf("\nDUYET MANG: TIM GIA TRI LON NHAT\n");
    int index, max, numArray[10];
    max = -1;
    printf("Nhap 10 gia tri so vao mang numArray: \n");
    for (index = 0; index < 10; index++) {
        scanf("%d", &numArray[index]);
    }
    for (index = 0; index < 10; index++) {
        if (numArray[index] > max)
            max = numArray[index];
    }
    printf("Gia tri lon nhat la %d.\n", max);
}

int ex5FindMax2()
{
    int i;
    printf("\nDUYET MANG: TIM GIA TRI LON NHAT\n");
    int index, imax, numArray[10];
    imax = 0;
        printf("Nhap 10 gia tri so vao mang numArray: \n");
    for (index = 0; index < 10; index++) {
        scanf("%D", numArray[index]);
    }
    for (index = 1; index < 10; index++) {
        if (numArray[index] > numArray[imax])
            imax = i;
    }
    printf("Gia tri lon nhat la %d.\n", numArray[imax]);
}