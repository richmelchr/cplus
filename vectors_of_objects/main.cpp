#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    // member variables
    string newName;
    char newGrade;

public:
    Student(); // default constructor
    Student(string name, char grade); // overloaded default constructor
    ~Student(); // destructor

    string getName()const; // const is a safety to make sure nothing gets changed inside the accessor function
    char getChar()const;

    void setName(string name); // mutator functions
    void setGrade(char grade);
};

void fillVector(vector<Student>& newMyClass); // fill in student information
void printVector(const vector<Student>& newMyClass); // always pass-in by reference because it is not default (like arrays) and takes up large memory | const is a safety to make sure nothing gets changed inside the function

int main() {

    vector<Student> myClass;

    fillVector(myClass);

    printVector(myClass);

    return 0;
}


void fillVector(vector<Student>& newMyClass) {
    int classSize;
    string name;
    char grade;

    cout << "How many students in class?: ";
    cin >> classSize;

    for (int i = 0; i < classSize; ++i) {
        cout << "Student name: ";
        cin >> name;
        cout << "Enter Student Grade: ";
        cin >> grade;

        Student newStudent(name, grade); // instantiating the object

        newMyClass.push_back(newStudent); // adding a new object to the newMyClass vector
    }
}

void printVector(const vector<Student>& newMyClass) {
    unsigned int size = newMyClass.size();

    for (unsigned int i = 0; i < size; ++i) {
        cout << "Student Name: " << newMyClass[i].getName() << endl;
        cout << "Student Grade: " << newMyClass[i].getChar() << endl;
    }
}


Student::Student() {newName = " "; newGrade = ' ';}
Student::Student(string name, char grade) {newName = name; newGrade = grade;}
Student::~Student() {}
string Student::getName()const {return newName;}
char Student::getChar()const {return newGrade;}
void Student::setName(string name) {newName = name;}
void Student::setGrade(char grade) {newGrade = grade;}
