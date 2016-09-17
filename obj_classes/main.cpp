#include <iostream>
#include <string>

using namespace std;

class BMI {
private:
    string newName;
    int newHeight;
    double newWeight;

public:
    BMI(); // default constructor
    BMI(string name, int height, double weight); // overloaded constructor
    ~BMI(); // de-structure, will be auto run when function implementing it ends

    // Accessor Functions
    string getName();
    int getHeight();
    double getWeight();

    // Mutator Functions
    void setName(string name);
    void setHeight(int height);
    void setWeight(double weight);
};


int main() {

    BMI Student_1; // as soon as an object is created the 'default constructor; is accessed and ran
//    BMI Student_1(drew, 68, 190); // if you want to create an object using your 'overloaded constructor' instead of 'default'

    string name;
    int height;
    double weight;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your height (in inches)";
    cin >> height;
    cout << "Enter your weight (in pounds)";
    cin >> weight;

    Student_1.setName(name);
    Student_1.setHeight(height);
    Student_1.setWeight(weight);

    cout << endl << "your name is: " << Student_1.getName() << endl;


    return 0;
}


BMI::BMI() {
    newName = "";
    newHeight = 0;
    newWeight = 0.0;
}
BMI::BMI(string name, int height, double weight) {
    newName = name;
    newHeight = height;
    newWeight = weight;
}
BMI::~BMI() {}

string BMI::getName() {return newName;}
int BMI::getHeight() {return newHeight;}
double BMI::getWeight() {return newWeight;}

void BMI::setName(string name) {newName = name;}
void BMI::setHeight(int height) {newHeight = height;}
void BMI::setWeight(double weight) {newWeight = weight;}
