#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    
    Number(int v = 0) : value(v) {}

    
    int getValue() const {
        return value;
    }

    
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    
    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }

    Number operator*(const Number& other) const {
        return Number(value * other.value);
    }

    
    friend ostream& operator<<(ostream& os, const Number& n) {
        os << n.value;
        return os;
    }
};

int main() {
    Number a(7), b(7);
    Number c = a + b;
    Number s = a - b;
    Number x = a * b;

    cout << c << endl << s << endl << x;
    return 0;
}
