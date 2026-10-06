#include <stdio.h>

int main() {
    float score;
    char grade;

    printf("Enter student's percentage score: ");
    scanf("%f", &score);

    if (score < 0 || score > 100) {
        printf("Error: Score must be between 0 and 100.\n");
        return 1;
    }

    if (score >= 90) {
        grade = 'A';
        printf("Grade: A\n");
        printf("Excellent work! Keep it up!\n");
    }
    else if (score >= 75) {
        grade = 'B';
        printf("Grade: B\n");
        printf("Good work! Keep improving!\n");
    }
    else if (score >= 60) {
        grade = 'C';
        printf("Grade: C\n");
        printf("Good effort! Keep working hard!\n");
    }
    else if (score >= 45) {
        grade = 'D';
        printf("Grade: D\n");
        printf("Keep practicing and improving!\n");
    }
    else {
        grade = 'F';
        printf("Grade: F\n");
        printf("Don't give up! Keep practicing!\n");
    }

    return 0;
}