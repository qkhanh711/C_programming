#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int maSP;
    char tenSP[100];
    char loaiSP[100];
    int soLuong;
    int donGia;
    int tongGiaTri;
} SanPham;

// Hàm so sánh để sắp xếp
int soSanh(const void *a, const void *b) {
    SanPham *sp1 = (SanPham *)a;
    SanPham *sp2 = (SanPham *)b;
    
    if (sp1->tongGiaTri != sp2->tongGiaTri)
        return sp2->tongGiaTri - sp1->tongGiaTri; // giảm dần theo tổng giá trị
    else
        return sp1->maSP - sp2->maSP; // tăng dần theo mã sản phẩm
}

int main() {
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");

    if (fi == NULL || fo == NULL) {
        printf("Không thể mở file.\n");
        return 1;
    }

    int n;
    fscanf(fi, "%d", &n);
    SanPham ds[n];

    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d %s %s %d %d",
               &ds[i].maSP,
               ds[i].tenSP,
               ds[i].loaiSP,
               &ds[i].soLuong,
               &ds[i].donGia);
        ds[i].tongGiaTri = ds[i].soLuong * ds[i].donGia;
    }

    qsort(ds, n, sizeof(SanPham), soSanh);

    for (int i = 0; i < n; i++) {
        fprintf(fo, "%d %s %s %d\n",
                ds[i].maSP,
                ds[i].tenSP,
                ds[i].loaiSP,
                ds[i].tongGiaTri);
    }

    fclose(fi);
    fclose(fo);
    return 0;
}
