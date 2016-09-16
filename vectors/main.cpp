#include <iostream>
#include <vector>
#include "string"
using namespace std;

void simpleVector(); // simple vector example
//void moreVector(); // move vector commands
void fillVector(vector<int>&); // by default vectors are not passed by reference, it is very important to pass by reference so make sure to include the "&"
void printVector(const vector<int>&); // since you won't be making any changes to the vector, it is best practices to pass it in as a constant
void reverse(const vector<int>&); // reverse the vector

int main() {
    vector<int> newVector;

    newVector.push_back(1);
    newVector.push_back(2);
    newVector.push_back(3);


    reverse(newVector);

    return 0;
}

void simpleVector() {
    vector<int> myVector;

    myVector.push_back(1); // add int to end of vector
    myVector.push_back(2);
    myVector.push_back(3);

    myVector.insert(myVector.begin(), 4); // inserts a 4 at the beginning of the vector
    myVector.insert(myVector.begin() + 2, 4); // inserts a 4, 2 positions into the vector
    myVector.erase(myVector.begin() + 2); // remove vector at this position
    myVector.clear(); // removes all elements in vector
    myVector.empty(); // returns boolean value if vector is empty

    cout << "Vector: ";

    for (unsigned int i = 0; i < myVector.size(); ++i) { // an 'unsigned int' and an 'int' are different variables
        cout << myVector[i] << " ";
    }
}

void fillVector(vector<int>& newMyVector) {
    cout << "type in a list of numbers (-1 to stop): ";
    int input;
    cin >> input;

    while (input != -1) { // ignore error, it is updated
        newMyVector.push_back(input);
        cin >> input;
    }
}

void printVector(const vector<int>& newMyVector) {
    for (unsigned int i = 0; i < newMyVector.size(); ++i) {
        cout << newMyVector[i] << " ";
    }
    cout << endl;
}

void reverse(const vector<int>& newMyVector) {
    cout << "Vector Reversed: ";
    int input;

    for (int i = newMyVector.size() -1; i >= 0 ; --i) {
        cout << newMyVector[i] << " ";
    }
}

