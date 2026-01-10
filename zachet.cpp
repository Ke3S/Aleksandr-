#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Student {
public:
    string surname;
    string group;
    int Physics;
    int informatics;
    int history;
    Student(string s, string g, int p, int i, int h)
        : surname(s), group(g), Physics(p), informatics(i), history(h) {
}

    double averageScore() {
        return (Physics + informatics + history) / 3.0;
}
    void print() {
        cout << "Фамилия: " << surname
            << ", Группа: " << group
            << ", Средняя балл: " << averageScore()
            << endl;
 }
};
int main() {
    SetConsoleCP(1251); // данные две строки написаны для отображения русского текста в консоль (ввод)
    SetConsoleOutputCP(1251); //(вывод), 1251 это стандарт для кодирования русского языка 
    Student students[8] = {
        {"Порваткин", "164", 5, 4, 4},
        {"Нестных", "164", 4, 5, 4},
        {"Рундау", "164", 3, 3, 5},
        {"Седышев", "164", 5, 5, 5},
        {"Михайлов", "164", 4, 5, 4},
        {"Дзелзайн", "144-2", 3, 4, 5},
        {"Токарев", "144-2", 5, 4, 4},
        {"Никишов", "144-2", 5, 5, 3}
};
    cout << "Студенты со средним баллом больше 4:" << endl;
    for (int i = 0; i < 8; ++i) {
        if (students[i].averageScore() > 4) {

            students[i].print();
 }
}

    return 0;
}