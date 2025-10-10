#include <iostream>

using namespace std;
class student {
private:
    int sum = 0;
    int count = 0;
public:
    void add_mark(int mark) {
        sum += mark;
        count++;
    }
    double get_average() {
        if (count == 0)return 0;
        return(double)sum / count;
    }
};

int main() {
    student student;
    student.add_mark(2);
    student.add_mark(2);
    student.add_mark(3);
    student.add_mark(3);
    cout << "sredniy ball:" << student.get_average() << endl;
    return 0;
}