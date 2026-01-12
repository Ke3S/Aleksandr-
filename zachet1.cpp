#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Student {
private: // добавив private мы скрываем данные (это один из принципов ООП "Инкапсуляция")
    string surname;
    string group;
    int Physics;
    int informatics;
    int history;
public: // а методы и конструктор мы оставляем public
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
    string getSurname() { return surname; } // геттеры для доступа к приватным полям 
    string getGroup() { return group; }
};

class MagistrStudent : public Student { // добавил для реализации второго столпа ООП "Наследование" новый класс (потомка)
private:
    string thesisTopic; // тема дипломной работы

public:
    MagistrStudent(string s, string g, int p, int i, int h, string topic)
        : Student(s, g, p, i, h), thesisTopic(topic) {
    }
    string getThesisTopic() { return thesisTopic; }

    void print() {
        Student::print(); // вызываем метод принт для родительского класса для вывода данных с базового класса студенты в классе магистрыстуденты
        cout << ", Тема дипломной работы: " << thesisTopic << endl;// + Тема дипломной работы
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
    MagistrStudent magistr[2] = {
        {"Набока", "164-2", 5, 5, 5, "Искусственный интеллект"},
        {"Павленко", "164-1", 4, 5, 4, "Информационная безопастность"}
    };
    cout << "\nБакалавриат:" << endl;
    cout << "Студенты со средним баллом больше 4:" << endl;
    for (int i = 0; i < 8; ++i) {
        if (students[i].averageScore() > 4) {

            students[i].print();
        }
    }
    cout << "\nМагистранты:" << endl;
    for (int i = 0; i < 2; ++i) {
        magistr[i].print();
    }
    return 0;

}
