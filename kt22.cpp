#include <iostream>
using namespace std;

class Shape {
protected:
    string name;
    string color;
public:
    Shape(const string& n = "", const string& c = "") : name(n), color(c) {}
    virtual void draw() const {
        cout << "Drawing " << name << " with color " << color << endl;
    }
    virtual double area() const = 0;
    bool operator==(Shape const& other) const {
        return (name == other.name) && (color == other.color);
    }
    friend ostream& operator<<(ostream& os, const Shape& ww) {
        os << ww.name << ", color: " << ww.color << ", area: " << ww.area() << endl;
        return os;
    }
};

class Circle : public Shape {
protected:
    float radius;
public:
    Circle(float r, const string& c = "") : Shape("Circle", c), radius(r) {}
    void draw() const override {
        cout << "radius Circle: " << radius << endl;
    }
    double area() const override {
        return radius * radius * 3.14;
    }
};

class Rectangle : public Shape {
protected:
    float width;
    float height;
public:
    Rectangle(float w, float h, const string& c = "") : Shape("Rectangle", c), width(w), height(h) {}
    void draw() const override {
        cout << "width=" << width << ", height=" << height << endl;
    }
    double area() const override {
        return width * height;
    }
};

void printInfo(const Shape& shape) {
    cout << "Basic info: " << shape << endl;
}

void printInfo(const Shape* shape) {
    cout << "Detailed info: ";
    shape->draw();
}

int main() {
    cout << "Hello Vladick!" << endl;

    Circle w(5, "Red");
    Rectangle g(4, 6, "Blue");

    Shape* shapes[] = { &w, &g };

    for (Shape* shape : shapes) {
        printInfo(*shape);
        printInfo(shape);
    }

    return 0;
}
