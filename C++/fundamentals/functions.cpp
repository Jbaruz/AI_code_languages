// Function on C++
// Author: JBA
// Date: 03-12-2024

#include <iostream>

using namespace std;

int add(int a, int b) {return a + b; }
double add(double a, double b) {return a + b; }

int main() {
    cout << "Integer sum: " << add(3, 5) << endl;
    cout << "Double sum: " << add(2.5, 3.5) << endl;
    return 0;
}