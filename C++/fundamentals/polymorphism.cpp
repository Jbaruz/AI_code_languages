// Polymorphism in C++
// Author: JBA
// Date: 05-12-2024

#include <iostream>
using namespace std;

class Shape {
    public:
        virtual void display() { // Virtual function
            cout << "This is a generic shape." << endl;
        }
};

class Rectangle : public Shape {
    public: 
        void display() override {
            cout << "This is a rectangle." << endl;
        }
};

int main() {
    Shape* shape = new Rectangle();
    shape -> display(); // Calls Rectangles display
    delete shape;
    return 0;
}
