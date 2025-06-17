#include<stdio.h>

int global = 10;

void modifyValue(int x){
    x = 100;
}

int main(){
    int a = 10;
    for (int i = 1; i < 5; i++){
        int bb = 4;
    }

    a  = global;
    // a = bb;
    print("%d", a);
}