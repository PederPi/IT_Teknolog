#include <stdio.h>

int main(void) {
    int array[5] = {5, 7, 2, 9, 8};
    int* ptrArray[5] = {&array[0], &array[1], &array[2], &array[3], &array[4]};
    printf_s("The elements you entered are:\n");
    for (int i = 0; i < 5; i++) {
        printf_s("element - %d: %d\n", i, *ptrArray[i]);
    }
    return 0;
}