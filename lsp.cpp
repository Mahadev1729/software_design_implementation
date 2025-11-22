#include <iostream>
using namespace std;

class Shape {
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() const override {
        return width * height;
    }
private:
    int width, height;
};

class Square : public Shape {
public:
    Square(int side) : side(side) {}
    int area() const override {
        return side * side;
    }
private:
    int side;
};

void printArea(const Shape& s) {
    cout << "Area: " << s.area() << endl;
}

int main() {
    Rectangle r(4, 5);
    Square s(4);

    printArea(r);   // Rectangle area → 20
    printArea(s);   // Square area → 16

    return 0;
}
