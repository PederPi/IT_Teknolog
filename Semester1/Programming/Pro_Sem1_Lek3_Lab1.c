#include <stdio.h>

int main(void) {
    int counter = 1;
    int sum = 0;
    while (counter < 11) {
        sum = sum + counter;
        counter++;
    }
    printf_s("%d", sum);
    return 0;
}