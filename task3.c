#include <stdio.h>

struct Student {
    char name[50];
    int rollno;
    float marks;
    char grade;
};

void assignGrade(struct Student *s) {
    if (s->marks >= 90)
        s->grade = 'A';
    else if (s->marks >= 75)
        s->grade = 'B';
    else if (s->marks >= 60)
        s->grade = 'C';
    else if (s->marks >= 45)
        s->grade = 'D';
    else
        s->grade = 'F';
}

int main() {
    struct Student students[3];

    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for Student %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Roll No: ");
        scanf("%d", &students[i].rollno);

        printf("Marks: ");
        scanf("%f", &students[i].marks);

        assignGrade(&students[i]);
    }

    printf("\n--- Student Records ---\n");
    printf("%-20s %-10s %-10s %-5s\n",
           "Name", "Roll No", "Marks", "Grade");

    for (int i = 0; i < 3; i++) {
        printf("%-20s %-10d %-10.2f %-5c\n",
               students[i].name,
               students[i].rollno,
               students[i].marks,
               students[i].grade);
    }

    return 0;
}