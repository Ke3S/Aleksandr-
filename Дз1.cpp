#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h> // Для русификации консоли

using namespace std;

class Student {
public:
    string name;
    int grade;

    Student(string name, int grade) : name(name), grade(grade) {}

    
    bool operator==(const Student& other) const {
        return name == other.name;
    }

  
    bool operator<(const Student& other) const {
        return grade < other.grade;
    }

    bool operator>(const Student& other) const {
        return grade > other.grade;
    }

    bool operator<=(const Student& other) const {
        return grade <= other.grade;
    }
};

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Student> students = {
        {"Алиса", 88},
        {"Борис", 72},
        {"Виктор", 95}
    };

    
    sort(students.begin(), students.end());

    cout << "Список студентов (отсортирован по оценкам):" << endl;
    for (const auto& s : students) {
        cout << s.name << " - " << s.grade << endl;
    }

    return 0;
}
