#include <iostream>
#include "Student.h"
#include "GraduationDao.h"

int main() {
    Student student1(1,"Demeter", "Botond");
    student1.addGrade("math", 8.9);
    student1.addGrade("romanian",6.7);
    student1.addGrade("hungarian", 8.6);
    cout << student1;
    cout << student1.getAverage();
    cout << endl;
    int numSubjects = 3;
    string subjects[] = {"math", "romanian", "hungarian"};
    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;
}