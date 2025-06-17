#include<stdio.h>

// struct Quat{
//     int so_canh;
//     int van_toc_gio;
//     char thuong_hieu[30];
// };

// int main(){
//     struct Quat aa;
//     struct Quat bb[4];
//     aa.so_canh = 4;
//     bb[0].van_toc_gio = 3;
//     printf("%d\n", aa.so_canh);
//     return 0;

// }
#define MAX 3

struct SinhVien {
    char ten[50];
    int tuoi;
    float diemGPA;
};

struct Date {
    int dat, month, year;
};

struct Student{
    char name[50];
    struct Date dob;
};

int main(){
    // struct SinhVien ds[MAX];
    // struct SinhVien *ptr = ds;

    // for (int i = 0; i < MAX; i++) {
    //     printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
    //     printf("Ten: ");
    //     scanf("%s", (ptr+i)->ten);
    //     printf("Tuoi: ");
    //     scanf("%d", &(ptr+i)->tuoi);
    //     printf("Diem GPA: ");
    //     scanf("%f", &(ptr+i)->diemGPA);
    // }

    // printf("\nDS sinh vien:\n");
    // for (int i = 0; i < MAX; i++) {
    //     printf("Sinh vien %d: Ten: %s, Tuoi: %d, Diem GPA: %.2f\n", 
    //            i + 1, (ptr+i)->ten, (ptr+i)->tuoi, (ptr+i)->diemGPA);
    // }
    struct Student sv;
    printf("Nhap ten: ");
    scanf("%s", sv.name);
    getchar();
    printf("Ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &sv.dob.dat, &sv.dob.month, &sv.dob.year);

    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s\n", sv.name);
    printf("Ngay sinh: %02d/%02d/%04d\n", sv.dob.dat, sv.dob.month, sv.dob.year);
    return 0;
}
