#include <iostream>
#include <string>
using namespace std;

/*Ієрархія типів складається з сутностей: студент, батько сімейства та
студент-батько сімейства*/

class Student {
protected:
    string titleOfSubject;
    int course;

public:
    Student() {}
    Student(string tit) { titleOfSubject = tit; }
    Student(string tit, int c) {
        titleOfSubject = tit;
        course = c;
    }
    friend ostream& operator<<(ostream& os, Student& a);
    friend istream& operator>>(istream& os, Student& a);
};

ostream& operator<<(ostream& out, Student& a) {
    out << " Title of subject" << a.titleOfSubject << " course:" << a.course;
    return out;
}
istream& operator>>(istream& in, Student& a) {
    cout << "Enter the tite of subject and course:";
    in >> a.titleOfSubject;
    in >> a.course;
    return in;
}

class FamilyDad {
protected:
    int kids;
    int merrigeDate;
    FamilyDad() {};
    FamilyDad(int k) { kids = k; };
    FamilyDad(int k, int merri) {
        kids = k;
        merrigeDate = merri;
    };
    friend ostream& operator<<(ostream& os, FamilyDad& a);
    friend istream& operator>>(istream& os, FamilyDad& a);
};

ostream& operator<<(ostream& out, FamilyDad& a) {
    out << "Kids:" << a.kids << "merrige date:" << a.merrigeDate << endl;
    return out;
}

istream& operator>>(istream& in, FamilyDad& a) {
    cout << "Enter the number of kids and merrige date:";
    in >> a.kids >> a.merrigeDate;
    return in;
}

class StudentFamilyDad : public Student, public FamilyDad {
public:
    StudentFamilyDad() {};
    StudentFamilyDad(string tit, int c, int k, int merrige)
        : FamilyDad(k, merrige), Student(tit, c) {}
    friend ostream& operator<<(ostream& os, StudentFamilyDad& a);
    friend istream& operator>>(istream& os, StudentFamilyDad& a);
};

ostream& operator<<(ostream& out, StudentFamilyDad& a) {
    out << "Title of subject:" << a.titleOfSubject << " course:" << a.course
        << " Kids:" << a.kids << " merrige date:" << a.merrigeDate << endl;
    return out;
};

istream& operator>>(istream& in, StudentFamilyDad& a) {
    cout << "Enter title of subject, course, kids, merrige date:";
    in >> a.titleOfSubject;
    in >> a.course;
    in >> a.kids;
    in >> a.merrigeDate;
    return in;
}

int example3() {
    StudentFamilyDad d;
    cin >> d;
    cout << d;
    return 0;
}
