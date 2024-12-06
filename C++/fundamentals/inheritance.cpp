// Inheritance on C++ programming
// Author: JBA
// Date: 05-12-2024

#include <iostream>
using namespace std;

class Shape {
    public:
        void display() {
            cout << "This is a shape." <<endl ;
        }
};

class Rectangle : public Shape {
    public:
        void display() {
            cout << " This is a rectangle." << endl;
        }
};

int main() {
    Rectangle rect;
    rect.display();
    return 0;
}
