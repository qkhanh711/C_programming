#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


typedef struct Car{
    char brand[10];
    char color[5];
    int seats;
    float price;
} Car;

Car input(){
    Car car;
    int color;
    printf("Ten hang xe: ");
    getchar();
    scanf("%[^\n]", &car.brand);
    // getchar();
    printf("Mau xe: ");
    scanf("%d", &color);
    // switch (color){
    //     case 1: 
    //         car.color = "Den";
    //     case 2:
    //         car.color = "Tran";
    //     case 3:
    //         car.color = "Bac";
    //     default:
    //         car.color = "Bac";
    //         break
    // }
    // getchar();
    printf("So cho ngoi: ");
    scanf("%d", &car.seats);
    
    printf("Gia ban: ");
    scanf("%d", &car.price);
    return car;
}

Car sort(Car *cars, int n){
    for (int i = 0, i < n; i++){
        for (int j = 1; j < n - i - 1; j++){
            if (cars[i].price < car[j]. price){
                Car temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }
        }
    }
}

void Gia(Car cars, int G1, int G2)
{
    for (int i = 0, i < n; i++){
        // for (int j = 1; j < n - i - 1; j++){
            if (cars[i].price > G1 && car[j].price < G2){
                display(cars[i]);
            }
        // }
    }
}    
void display(Car *cars){
    printf("+-----+------+----------+-------------+---------------------------+");
    printf("| STT |  Mau |  Hang xe | So cho ngoi + Gia ban (trieu VND)       +");
    for (int i = 0; i < n;i++){
        // cars[i] = input();
        printf("|%d |%d |%s |%d|%d|", i+1, car.color, car.brand, car.seats, car.price);
        printf("+-----+------+----------+-------------+---------------------------+");
    }
}

int main(){
    int n;
    printf("Nhap so xe");
    scanf("%d", &n);
    Car cars[1000];
    for (int i = 0; i < n;i++){
        cars[i] = input();
    }
    printf("+-----+------+----------+-------------+---------------------------+");
    printf("| STT |  Mau |  Hang xe | So cho ngoi + Gia ban (trieu VND)       +");
    for (int i = 0; i < n;i++){
        // cars[i] = input();
        printf("|%d |%d |%s |%d|%d|", i+1, car.color, car.brand, car.seats, car.price);
        printf("+-----+------+----------+-------------+---------------------------+");
    }
    display(cars);
    sort(cars, 10);
}