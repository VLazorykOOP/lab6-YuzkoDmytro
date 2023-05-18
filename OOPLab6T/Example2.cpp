#include <iostream>
using namespace std;

/*Створити абстрактний базовий клас фігура із віртуальною функцією
площа. Створити похідні класи: прямокутник, коло, прямокутний трикутник,
трапеція зі своїми функціями площі.*/

class Figure {
public:
    string name;
    virtual float S() = 0;
};

class Rectangle : public Figure {
    float width, height;

public:
    Rectangle(float w, float h) : width(w), height(h) { name = "Rectangle"; }
    virtual float S() override { return width * height; }
};

class Circle : public Figure {
    float radius;

public:
    Circle(float r) : radius(r) { name = "Circle"; }
    virtual float S() override { return 3.14159 * radius * radius; }
};

class RightTriangle : public Figure {
    float base, height;

public:
    RightTriangle(float b, float h) : base(b), height(h) {
        name = "RightTriangle";
    }
    virtual float S() override { return 0.5 * base * height; }
};

class Trapezoid : public Figure {
    float base1, base2, height;

public:
    Trapezoid(float b1, float b2, float h) : base1(b1), base2(b2), height(h) {
        name = "Trapezoid";
    }
    virtual float S() override { return (base1 + base2) * height / 2; }
};

int example2() {

    cout << "RESULT:\n";
    Rectangle r(2, 3);
    Circle c(4);
    RightTriangle t(3, 4);
    Trapezoid z(2, 5, 3);

    Figure* figures[] = { &r, &c, &t, &z };
    int n = sizeof(figures) / sizeof(Figure*);

    for (int i = 0; i < n; i++) {
        cout << "S of figure " << figures[i]->name << ": " << figures[i]->S()
            << endl;
    }
    return 0;
}
