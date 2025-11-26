#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// ===== Point Class =====
class Point {
private:
    double m_x, m_y;

public:
    Point(double x = 0, double y = 0) : m_x(x), m_y(y) {}

    void move(double dx, double dy) {
        m_x += dx;
        m_y += dy;
    }

    void Read() {
        cout << "Enter the coordinates of the point (x y): ";
        cin >> m_x >> m_y;
    }

    void Display() const {
        cout << "Point: (" << m_x << ", " << m_y << ")" << endl;
    }
};

// ===== Calculator Class =====
class Calculator {
public:
    double add(double a, double b) const { return a + b; }
    double subtract(double a, double b) const { return a - b; }
    double multiply(double a, double b) const { return a * b; }
    double divide(double a, double b) const {
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;
    }
};

// ===== Student Class =====
class Student {
private:
    string m_name;
    int m_age;
    double m_averageGrade;

public:
    Student(string name = "", int age = 0, double averageGrade = 0.0)
        : m_name(name), m_age(age), m_averageGrade(averageGrade) {
    }

    void Read() {
        cout << "Enter the student's name, age, and average grade: ";
        cin >> m_name >> m_age >> m_averageGrade;
    }

    void Display() const {
        cout << "Student: " << m_name << ", Age: " << m_age
            << ", Average Grade: " << m_averageGrade << endl;
    }

    string getName() const { return m_name; }
    int getAge() const { return m_age; }
    double getAverageGrade() const { return m_averageGrade; }
};

// ===== StudentManager Class =====
class StudentManager {
private:
    vector<Student> m_students;

public:
    void addStudent(const Student& student) {
        m_students.push_back(student);
    }

    void removeStudent(const string& name) {
        for (auto it = m_students.begin(); it != m_students.end(); ++it) {
            if (it->getName() == name) {
                m_students.erase(it);
                break;
            }
        }
    }

    void displayAll() const {
        for (const auto& student : m_students) {
            student.Display();
        }
    }
};

// ===== Book Class =====
class Book {
private:
    string m_title;
    string m_author;
    int m_year;

public:
    Book(string title = "", string author = "", int year = 0)
        : m_title(title), m_author(author), m_year(year) {
    }

    void Read() {
        cout << "Enter the book's title, author, and year of publication: ";
        cin >> m_title >> m_author >> m_year;
    }

    void Display() const {
        cout << "Book: " << m_title << ", Author: " << m_author
            << ", Year: " << m_year << endl;
    }

    int getYear() const { return m_year; }
};

bool compareByYear(const Book& a, const Book& b) {
    return a.getYear() < b.getYear();
}

// ===== BankAccount Class =====
class BankAccount {
private:
    string m_accountNumber;
    double m_balance;

public:
    BankAccount(string accountNumber = "", double balance = 0.0)
        : m_accountNumber(accountNumber), m_balance(balance) {
    }

    void deposit(double amount) {
        if (amount > 0) m_balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= m_balance) m_balance -= amount;
    }

    void transfer(BankAccount& other, double amount) {
        if (amount > 0 && amount <= m_balance) {
            m_balance -= amount;
            other.m_balance += amount;
        }
    }

    void Read() {
        cout << "Enter the account number and balance: ";
        cin >> m_accountNumber >> m_balance;
    }

    void Display() const {
        cout << "Account: " << m_accountNumber << ", Balance: " << m_balance << endl;
    }
};

// ===== Main Function =====
int main() {
    // Working with Point class
    cout << "=== Point Class ===" << endl;
    Point p;
    p.Read();
    p.Display();
    p.move(2, 3);
    p.Display();

    // Working with Calculator class
    cout << "\n=== Calculator Class ===" << endl;
    Calculator calc;
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Sum: " << calc.add(a, b) << endl;
    cout << "Difference: " << calc.subtract(a, b) << endl;
    cout << "Product: " << calc.multiply(a, b) << endl;
    cout << "Quotient: " << calc.divide(a, b) << endl;

    // Working with Student and StudentManager classes
    cout << "\n=== Student and StudentManager Classes ===" << endl;
    StudentManager manager;
    Student student1, student2;
    student1.Read();
    student2.Read();
    manager.addStudent(student1);
    manager.addStudent(student2);
    manager.displayAll();
    manager.removeStudent(student1.getName());
    manager.displayAll();

    // Working with Book class
    cout << "\n=== Book Class ===" << endl;
    vector<Book> books;
    Book book1, book2;
    book1.Read();
    book2.Read();
    books.push_back(book1);
    books.push_back(book2);
    sort(books.begin(), books.end(), compareByYear);
    for (const auto& book : books) {
        book.Display();
    }

    // Working with BankAccount class
    cout << "\n=== BankAccount Class ===" << endl;
    BankAccount account1, account2;
    account1.Read();
    account2.Read();
    account1.deposit(1000);
    account1.withdraw(500);
    account1.transfer(account2, 300);
    account1.Display();
    account2.Display();

    return 0;
}
