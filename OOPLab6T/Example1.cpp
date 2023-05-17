#include <iostream>
using namespace std;

/*Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з
елементами даних класів у кожному класі. Схема успадкування на рисунку за
варіантами. Створити об’єкти похідних класів з віртуальним та без віртуального
успадкуванням. Вивести розміри об’єктів даних класів.
*/
class Base {
protected:
    int dat;

public:
    Base() { dat = 0; }
    Base(int d) { dat = d; }
};

class DL1 : protected Base {
protected:
    int dl1;

public:
    DL1() : Base() { dl1 = 0; }
    DL1(int d) : Base() { dl1 = d; }
    DL1(int d, int dt) : Base(dt) { dl1 = d; }
};

class DL2 : protected DL1 {
protected:
    int dl2;

public:
    DL2() : DL1() { dl2 = 0; }
    DL2(int dl) : DL1() { dl2 = dl; }
    DL2(int dl, int dl2) : DL1(dl2) { dl2 = dl; }
    DL2(int dl, int dl2, int d) : DL1(dl2, d) { dl2 = dl; }

    void print() { cout << DL1::Base::dat; }
};

class DR1 : public Base {
public:
    int dr1;
    DR1() : Base() { dr1 = 0; }
    DR1(int dr) : Base() { dr1 = dr; }
    DR1(int dr, int d) : Base(d) { dr1 = dr; }
};

class DR2 : public DR1 {
public:
    int dr2;
    DR2() : DR1() { dr2 = 0; }
    DR2(int dr) : DR1() { dr2 = dr; }
    DR2(int dr, int drr) : DR1(drr) { dr2 = dr; }
    DR2(int dr, int drr, int d) : DR1(drr, d) { dr2 = dr; }
};

class R : public Base, public DR2, public DL2 {
public:
    int dt;
    R() : Base(), DR2(), DL2() { dt = 0; }
    R(int d) : Base(), DR2(), DL2() { dt = d; }
    R(int d, int ld1, int ld2, int rd1, int rd2, int main)
        : Base(main), DR2(rd1, rd2, main), DL2(ld1, ld2, main) {
        dt = d;
    }
    void print() {
        std::cout << "dat =? Error C2385 ambiguous access level dat " << std::endl;
    }
};
 //Початок віртуального успадкування:

class DVR1 : virtual public Base {
public:
    int dr1;
    DVR1() : Base() { dr1 = 0; }
    DVR1(int dr) : Base() { dr1 = dr; }
    DVR1(int dr, int d) : Base(d) { dr1 = dr; }
};

class DVR2 : virtual public DVR1 {
public:
    int dr2;
    DVR2() : DVR1() { dr2 = 0; }
    DVR2(int dr) : DVR1() { dr2 = dr; }
    DVR2(int dr, int drr) : DVR1(drr) { dr2 = dr; }
    DVR2(int dr, int drr, int d) : DVR1(drr, d) { dr2 = dr; }
};

class DVL1 : virtual protected Base {
protected:
    int dl1;

public:
    DVL1() : Base() { dl1 = 0; }
    DVL1(int d) : Base() { dl1 = d; }
    DVL1(int d, int dt) : Base(dt) { dl1 = d; }
};

class DVL2 : virtual protected DVL1 {
protected:
    int dl2;

public:
    DVL2() : DVL1() { dl2 = 0; }
    DVL2(int dl) : DVL1() { dl2 = dl; }
    DVL2(int dl, int dl2) : DVL1(dl2) { dl2 = dl; }
    DVL2(int dl, int dl2, int d) : DVL1(dl2, d) { dl2 = dl; }
};

class RV : virtual public Base, virtual public DVR2, virtual public DVL2 {
public:
    int dt;
    RV() : Base(), DVR2(), DVL2() { dt = 0; }
    RV(int d) : Base(), DVR2(), DVL2() { dt = d; }
    RV(int d, int ld1, int ld2, int rd1, int rd2, int main)
        : Base(main + 1), DVR2(rd1, rd2, main), DVL2(ld1, ld2, main) {
        dt = d;
    }
    void print() {
        std::cout << "dat = " << dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "DVR2::DVR1::Base::dat = " << DVR2::DVR1::Base::dat
            << std::endl;
        std::cout << "DVL2::DVL1::Base::dat = " << DVR2::DVR1::Base::dat
            << std::endl;
    }
};

int main() {

    std::cout << "  RESULT:  \n";
    RV d(1, 2, 3, 4.5, 5, 6);
    R r(1, 2, 3, 4.5, 5, 6);

    std::cout << "Size for Base " << sizeof(Base) << std::endl;
    std::cout << "Size for DR1 " << sizeof(DR1) << std::endl;
    std::cout << "Size for DR2 " << sizeof(DR2) << std::endl;
    std::cout << "Size for DL1 " << sizeof(DL1) << std::endl;
    std::cout << "Size for DL2 " << sizeof(DL2) << std::endl;
    std::cout << "Size for Base " << sizeof(Base) << std::endl;
    std::cout << "Size for DVL1 " << sizeof(DVL1) << std::endl;
    std::cout << "Size for DVL2 " << sizeof(DVL2) << std::endl;
    std::cout << "Size for DVR1 " << sizeof(DVR1) << std::endl;
    std::cout << "Size for DVR2 " << sizeof(DVR2) << std::endl;
    r.print();
    d.print();
    return 0;
}
