#include <iostream>
using namespace std;

class StudentInfo {
public:
    string name;
    int id;
    int section;
    const int intake = 36;

    StudentInfo(string a, int b , int c )  {
        name = a;
        id = b;
        section  = c;
        
    }
};

int main() {
    StudentInfo students[5] = {
        {"Talha", 36, 1},
        {"Talba", 37, 2},
        {"Talja", 38, 3},
        {"Talka", 39, 4},
        {"Talta", 40, 5}
    };

   

    cout << "Student Information:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << students[i].name << "  " << students[i].id << "  " << students[i].section << "  " << students[i].intake << endl;
    }

    return 0;
}
