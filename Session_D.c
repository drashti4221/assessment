#include <stdio.h>

int main() {
    int arr[10];
    int i, j, temp;
    int max, min;
    int sum = 0;
    float mean;
    float midpoint;

    printf("Enter 10 integers:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }
    }

    mean = (float)sum / 10;

    printf("\nMaximum = %d", max);
    printf("\nMinimum = %d", min);
    printf("\nMean = %.2f", mean);

    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSorted array: ");

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    midpoint = (min + max) / 2.0;

    if (mean < midpoint) {
        printf("\nMean is closer to the minimum.");
    }
    else if (mean > midpoint) {
        printf("\nMean is closer to the maximum.");
    }
    else {
        printf("\nMean is exactly midway between the minimum and maximum.");
    }

    return 0;
}