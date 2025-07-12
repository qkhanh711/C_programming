#include <stdio.h>

typedef struct Product
{
    int id;
    char name[30];
    char type[30];
    int number;
    int price;
} Product;

int main()
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (input == NULL)
    {
        printf("Can not open file!\n");
        return 1;
    }

    // int line
    int n;
    fscanf(input, "%d", &n);
    Product products[1000];
    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d %s %s %d %d", &products[i].id, products[i].name, products[i].type, &products[i].number, &products[i].price);
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int value_i = products[i].number * products[i].price;
            int value_j = products[j].number * products[j].price;

            if (value_i < value_j || (value_i == value_j && products[i].id > products[j].id)){
            // if (products[i].number * products[i].price < products[j].number * products[j].price){
                printf("%d %d\n", products[i].number * products[i].price, products[j].number * products[j].price);
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(output, "%d %s %s %d\n", products[i].id, products[i].name, products[i].type, products[i].number * products[i].price);
    }

    fclose(output);
}