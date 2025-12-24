#include <iostream>
#include <windows.h> // Для русификации консоли

using namespace std;

class CVector2D {
private:
    double x;
    double y;

public:
    
    CVector2D(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}

    // Геттеры для координат
    double getX() const { return x; }
    double getY() const { return y; }

   
    CVector2D operator+(const CVector2D& vector2) const {
        return CVector2D(x + vector2.x, y + vector2.y);
    }

    
    CVector2D operator-(const CVector2D& vector2) const {
        return CVector2D(x - vector2.x, y - vector2.y);
    }

   
    double operator*(const CVector2D& vector2) const {
        return x * vector2.x + y * vector2.y;
    }

   
    CVector2D operator*(double scalar) const {
        return CVector2D(x * scalar, y * scalar);
    }

   
    double& operator[](int index) {
        if (index == 0) return x;
        return y;
    }

  
    const double& operator[](int index) const {
        if (index == 0) return x;
        return y;
    }
};


CVector2D operator*(double scalar, const CVector2D& vector) {
    return CVector2D(scalar * vector.getX(), scalar * vector.getY());
}

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CVector2D v1(3, 3);
    CVector2D v2(2, 2);

    CVector2D sum = v1 + v2;
    double dot = v1 * v2;
    CVector2D scaled = v1 * 2.5;

    cout << "Сумма векторов: (" << sum.getX() << ", " << sum.getY() << ")" << endl;
    cout << "Скалярное произведение: " << dot << endl;
    cout << "Вектор после масштабирования: (" << scaled.getX() << ", " << scaled.getY() << ")" << endl;
    cout << "Первая координата v1: " << v1[0] << endl;

    return 0;
}
