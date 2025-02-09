#include <bits/stdc++.h>
using namespace std;

double calculateGPA(const vector<double>& grades, const vector<int>& credits) {
    double totalGradePoints = 0, totalCredits = 0;
    
    for (size_t i = 0; i < grades.size(); i++) {
        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }
    
    return (totalCredits == 0) ? 0 : (totalGradePoints / totalCredits);
}

int main() {
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    double cumulativeGradePoints = 0, cumulativeCredits = 0;

    for (int sem = 1; sem <= numSemesters; sem++) {
        int numCourses;
        cout << "\nEnter number of courses " << sem << ": ";
        cin >> numCourses;

        vector<double> grades(numCourses);
        vector<int> credits(numCourses);
        double semesterGradePoints = 0, semesterCredits = 0;

        for (int i = 0; i < numCourses; i++) {
            cout << "Enter grade " << i + 1 << ": ";
            cin >> grades[i];
            cout << "Enter credits " << i + 1 << ": ";
            cin >> credits[i];

            semesterGradePoints += grades[i] * credits[i];
            semesterCredits += credits[i];
        }

        double semesterGPA = calculateGPA(grades, credits);
        cout << "\nGPA for Semester " << sem << ": " << semesterGPA << endl;

        cumulativeGradePoints += semesterGradePoints;
        cumulativeCredits += semesterCredits;
    }

    double cgpa = (cumulativeCredits == 0) ? 0 : (cumulativeGradePoints / cumulativeCredits);
    cout << "\nFinal CGPA: " << cgpa << endl;

    return 0;
}
