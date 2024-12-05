// Encapsulation on C**
// Authos: JBA
// Date: 04-12-2024

#include <iostream>
using namespace std;

class Rectangle {
    private:
        double  length, width;
    public:
        void setDimensions(double l, double w) {
            length = l;
            width = w;
        }

        double calculateArea() {
            return length * width;
        }
};

int main() {
    Rectangle rect;
    rect.setDimensions(5.0, 3.0);
    cout << "Area: " << rect.calculateArea() << endl;
    return 0;
}