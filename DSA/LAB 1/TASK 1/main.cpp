#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string course_code;
    string course_name;
};

class Grade {
public:
    int mark;
    char the_grade;

    void calculateGrade() {
        if (mark > 69) {
            the_grade = 'A';
        } else if (mark > 59) {
            the_grade = 'B';
        } else if (mark > 49) {
            the_grade = 'C';
        } else if (mark > 39) {
            the_grade = 'D';
        } else {
            the_grade = 'E';
        }
    }
};

class Student {
public:
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated;

    void addStudent();
    void editStudent();
    void addMarksAndCalculateGrades();
};

void Student::addStudent() {
    cout << "Enter registration number: ";
    cin >> reg_number;

    cout << "Enter student name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter course code: ";
    cin >> course.course_code;

    cout << "Enter course name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, course.course_name);

    grades_calculated = false; // Initialize grades_calculated flag

    cout << "Student added successfully.\n";
}

void Student::editStudent() {
    cout << "Enter new age: ";
    cin >> age;

    cout << "Enter new course code: ";
    cin >> course.course_code;

    cout << "Enter new course name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, course.course_name);

    cout << "Student details edited successfully.\n";
}

void Student::addMarksAndCalculateGrades() {
    cout << "Enter mark (between 0 and 100): ";
    cin >> grades.mark;

    grades.calculateGrade(); // Calculate grade based on the grading system

    grades_calculated = true; // Set grades_calculated flag

    cout << "Marks added and grades calculated successfully.\n";
}

int main() {
    const int MAX_STUDENTS = 40;
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    char choice;
    do {
        cout << "1. Add Student\n";
        cout << "2. Edit Student Details\n";
        cout << "3. Add Marks and Calculate Grades\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                if (numStudents < MAX_STUDENTS) {
                    students[numStudents].addStudent();
                    numStudents++;
                } else {
                    cout << "Maximum number of students reached.\n";
                }
                break;
            case '2':
                if (numStudents > 0) {
                    string regNum;
                    cout << "Enter registration number to edit: ";
                    cin >> regNum;

                    int index = -1;
                    for (int i = 0; i < numStudents; ++i) {
                        if (students[i].reg_number == regNum) {
                            index = i;
                            break;
                        }
                    }

                    if (index != -1) {
                        students[index].editStudent();
                    } else {
                        cout << "Student not found.\n";
                    }
                } else {
                    cout << "No students to edit.\n";
                }
                break;
            case '3':
                if (numStudents > 0) {
                    string regNum;
                    cout << "Enter registration number to add marks: ";
                    cin >> regNum;

                    int index = -1;
                    for (int i = 0; i < numStudents; ++i) {
                        if (students[i].reg_number == regNum) {
                            index = i;
                            break;
                        }
                    }

                    if (index != -1) {
                        if (!students[index].grades_calculated) {
                            students[index].addMarksAndCalculateGrades();
                        } else {
                            cout << "Grades already calculated and cannot be altered.\n";
                        }
                    } else {
                        cout << "Student not found.\n";
                    }
                } else {
                    cout << "No students to add marks.\n";
                }
                break;
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}
