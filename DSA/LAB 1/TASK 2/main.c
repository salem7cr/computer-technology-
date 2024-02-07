#include <stdio.h>
#include <string.h>

// Define course structure
struct Course {
    char course_code[10];
    char course_name[50];
};

// Define grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define student structure
struct Student {
    char registration_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grade;
};

// Function to calculate grade based on mark
char calculateGrade(int mark) {
    if (mark > 69)
        return 'A';
    else if (mark > 59)
        return 'B';
    else if (mark > 49)
        return 'C';
    else if (mark > 39)
        return 'D';
    else
        return 'E';
}

int main() {
    const int MAX_STUDENTS = 40;
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    // Add student function
    void addStudent() {
        if (studentCount < MAX_STUDENTS) {
            printf("Enter registration number: ");
            scanf("%s", students[studentCount].registration_number);
            printf("Enter name: ");
            scanf("%s", students[studentCount].name);
            printf("Enter age: ");
            scanf("%d", &students[studentCount].age);
            printf("Enter course code: ");
            scanf("%s", students[studentCount].course.course_code);
            printf("Enter course name: ");
            scanf("%s", students[studentCount].course.course_name);
            studentCount++;
        } else {
            printf("Maximum number of students reached.\n");
        }
    };

    // Edit student function
    void editStudent() {
        char regNum[20];
        printf("Enter registration number of student to edit: ");
        scanf("%s", regNum);
        for (int i = 0; i < studentCount; ++i) {
            if (strcmp(students[i].registration_number, regNum) == 0) {
                printf("Enter new name: ");
                scanf("%s", students[i].name);
                printf("Enter new age: ");
                scanf("%d", &students[i].age);
                printf("Enter new course code: ");
                scanf("%s", students[i].course.course_code);
                printf("Enter new course name: ");
                scanf("%s", students[i].course.course_name);
                break;
            }
        }
    };

    // Add marks and calculate grade function
    void addMarksAndCalculateGrade() {
        char regNum[20];
        printf("Enter registration number of student to add marks: ");
        scanf("%s", regNum);
        for (int i = 0; i < studentCount; ++i) {
            if (strcmp(students[i].registration_number, regNum) == 0) {
                printf("Enter mark: ");
                scanf("%d", &students[i].grade.mark);
                students[i].grade.the_grade = calculateGrade(students[i].grade.mark);
                break;
            }
        }
    };

    // Display student details function
    void displayStudents() {
        printf("Registered students:\n");
        for (int i = 0; i < studentCount; ++i) {
            printf("Registration Number: %s\n", students[i].registration_number);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Course Code: %s\n", students[i].course.course_code);
            printf("Course Name: %s\n", students[i].course.course_name);
            printf("Grade: %c\n\n", students[i].grade.the_grade);
        }
    };

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Add Student\n");
        printf("2. Edit Student Details\n");
        printf("3. Add Marks and Calculate Grade\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                editStudent();
                break;
            case 3:
                addMarksAndCalculateGrade();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
