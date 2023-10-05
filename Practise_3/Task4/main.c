#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    double arr[n];
    int count = 0;
    double sum_after_negative = 0;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = (((rand() % 10001) / 100.0) - 50.0);
    }

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double average = sum / n;

    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            count++;
        }
    }

    int negative_found = 0;
    for (int i = 0; i < n; i++) {
        if (!negative_found && arr[i] < 0) {
            negative_found = 1;
        }

        if (negative_found) {
            sum_after_negative += fabs(arr[i]);
        }
    }

    printf("Number of elements greater than the average: %d\n", count);
    printf("Sum of absolute values after the first negative element: %.2lf\n", sum_after_negative);

    return 0;
}
