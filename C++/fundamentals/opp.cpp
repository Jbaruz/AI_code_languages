// Classes and objects
// Author: JBA
// Date: 04-12-2024

#include <iostream>
using namespace std;

class Rectangule {
    public:
        double length, width;

        double calculateArea() {
            return length * width; 
        }
};

int main() {
    Rectangule rect;
    rect.length = 5.0;
    rect.width = 3.0;
    cout << "Area: " << rect.calculateArea() << endl;
    return 0;
}