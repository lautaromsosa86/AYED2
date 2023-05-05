#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;

    for (unsigned int i = 0; i < length; i++) {
        if(!(arr[i] <= value)) {
            res.is_upperbound = res.is_upperbound && false;
        }
        if(!(arr[i] >= value)) {
            res.is_lowerbound = res.is_lowerbound && false;
        } 
        if(arr[i] == value) {
            res.exists = true;
            res.where = i;
        }
    }

    return res;
}

int main(void) {

    int a[ARRAY_SIZE];
    int value;
    

    printf("Ingrese uno por uno los elementos del array[4]: \n");
    for (unsigned int i = 0; i < ARRAY_SIZE; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Ingrese un valor para verificar con check_bound() = ");
    scanf("%d", &value);
    printf("\n");

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);
    

    if(result.exists) {
        if(result.is_upperbound) {
            printf("%d es maximo\n", value);
        }
        if(result.is_lowerbound) {
            printf("%d es minimo\n", value);
        }
    printf("Posicion de value en el arreglo: %d\n\n", result.where);
    } else {
        if(result.is_upperbound) {
            printf("%d es cota superior\n\n", value);
        }
        if(result.is_lowerbound) {
            printf("%d es cota inferior\n\n", value);
        }
    }
    return EXIT_SUCCESS;
}

