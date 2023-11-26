#include <stdio.h>
#include <time.h>
int main(void) {
    double start, end;
    int value;
    int count = 1;
    int testValue = 2;
    printf("PrimeNumber: ");
    scanf("%d", &value);
    start = (double) clock() / CLOCKS_PER_SEC;
    if (value <= 0) {
        printf("insert number bigger than 0\n");
    }
    while (count <= value) {
        int passFail = 0;
        for (int div = 2; div < testValue - 1; div++) {
            if (testValue % div == 0) {
                passFail = 1;
                testValue++;
                break;
            }
        }
        if (passFail == 0) {
            printf("%d\t", testValue);
            count++;
            testValue++;
        }
    }
    end = (((double) clock()) / CLOCKS_PER_SEC);
    printf("time: %1f", (end - start));
    return 0;
}