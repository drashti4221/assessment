#include <stdio.h>

int main() {
    float hours[7];
    float total = 0;
    float average;
    int highestDay = 0;

    // Accept study hours for 7 days
    for (int i = 0; i < 7; i++) {
        do {
            printf("Enter study hours for Day %d: ", i + 1);
            scanf("%f", &hours[i]);

            if (hours[i] < 0 || hours[i] > 24) {
                printf("Invalid input! Please enter hours between 0 and 24.\n");
            }

        } while (hours[i] < 0 || hours[i] > 24);

        total += hours[i];

        if (hours[i] > hours[highestDay]) {
            highestDay = i;
        }
    }

    average = total / 7;

    printf("\n--- Weekly Study Summary ---\n");
    printf("Weekly Total: %.2f hours\n", total);
    printf("Daily Average: %.2f hours\n", average);
    printf("Highest Study Hours: Day %d (%.2f hours)\n",
           highestDay + 1, hours[highestDay]);

    // Visual bar
    printf("\nStudy Hours Chart:\n");

    for (int i = 0; i < 7; i++) {
        int stars = (int)(hours[i] + 0.5);

        printf("Day %d: ", i + 1);

        for (int j = 0; j < stars; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}