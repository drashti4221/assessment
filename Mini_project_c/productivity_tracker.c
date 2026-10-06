#include <stdio.h>

#define SUBJECTS 3
#define DAYS 7

struct StudyLog {
    char subject[40];
    float hours[7];
};

void weeklyReport(struct StudyLog logs[]) {
    printf("\n===== Weekly Report =====\n");

    for (int i = 0; i < SUBJECTS; i++) {
        float total = 0;

        for (int j = 0; j < DAYS; j++) {
            total += logs[i].hours[j];
        }

        printf("\nSubject: %s\n", logs[i].subject);
        printf("Weekly Total: %.2f hours\n", total);
        printf("Daily Average: %.2f hours\n", total / DAYS);

        printf("Progress: ");

        int dots = (int)(total + 0.5);

        for (int j = 0; j < dots; j++) {
            printf("*");
        }

        printf("\n");
    }
}

void saveData(struct StudyLog logs[]) {
    FILE *file = fopen("productivity_log.txt", "w");

    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return;
    }

    for (int i = 0; i < SUBJECTS; i++) {
        fprintf(file, "%s", logs[i].subject);

        for (int j = 0; j < DAYS; j++) {
            fprintf(file, ",%.2f", logs[i].hours[j]);
        }

        fprintf(file, "\n");
    }

    fclose(file);

    printf("\nData saved to productivity_log.txt\n");
}

int main() {
    struct StudyLog logs[SUBJECTS] = {
        {"C Programming", {0}},
        {"HTML CSS", {0}},
        {"JavaScript", {0}}
    };

    int choice;

    do {
        printf("\n===== Student Productivity Tracker =====\n");
        printf("1. Log Today's Study Hours\n");
        printf("2. View Weekly Report\n");
        printf("3. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int day;

            printf("\nEnter day number (1-7): ");
            scanf("%d", &day);

            if (day < 1 || day > 7) {
                printf("Invalid day! Please enter 1 to 7.\n");
                continue;
            }

            for (int i = 0; i < SUBJECTS; i++) {
                do {
                    printf("Enter study hours for %s: ",
                           logs[i].subject);
                    scanf("%f", &logs[i].hours[day - 1]);

                    if (logs[i].hours[day - 1] < 0 ||
                        logs[i].hours[day - 1] > 24) {
                        printf("Invalid hours! Enter between 0 and 24.\n");
                    }

                } while (logs[i].hours[day - 1] < 0 ||
                         logs[i].hours[day - 1] > 24);
            }

        } else if (choice == 2) {
            weeklyReport(logs);

        } else if (choice == 3) {
            saveData(logs);
            printf("Program exited successfully.\n");

        } else {
            printf("Invalid choice! Please select 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}