#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() const override { return w * h; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() const override { return 3.14 * r * r; }
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
};

int main() {
    Shape* s1 = new Rectangle(4, 5);
    Shape* s2 = new Circle(3);
    Shape* s3 = new Triangle(6, 4);

    cout << s1->area() << endl;
    cout << s2->area() << endl;
    cout << s3->area() << endl;

    delete s1;
    delete s2;
    delete s3;
    return 0;
}
#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() const override { return w * h; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() const override { return 3.14 * r * r; }
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
};

int main() {
    Shape* s1 = new Rectangle(4, 5);
    Shape* s2 = new Circle(3);
    Shape* s3 = new Triangle(6, 4);

    cout << s1->area() << endl;
    cout << s2->area() << endl;
    cout << s3->area() << endl;

    delete s1;
    delete s2;
    delete s3;
    return 0;
}
