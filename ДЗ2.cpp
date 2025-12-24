#include <iostream>
#include <windows.h> // Для русификации консоли

using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    
    double getReal() const {
        return real;
    }

    
    double getImaginary() const {
        return imaginary;
    }

   
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
        );
    }

    Complex operator~() const {
        return Complex(real, -imaginary);
    }

    
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imaginary >= 0)
            os << " + " << c.imaginary << "i";
        else
            os << " - " << -c.imaginary << "i";
        return os;
    }
};

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex product = c1 * c2;
    Complex conjugate = ~c1;
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Произведение c1 * c2 = " << product << endl;
    cout << "Сопряжённое ~c1 = " << conjugate << endl;
    cout << "Сумма c1 + c2 = " << sum << endl;
    cout << "Разность c1 - c2 = " << diff << endl;

    return 0;
}
