#include <iostream>
using namespace std;

int main() {
    int a = 12; // 1100
    int b = 10; // 1010

    cout << (a & b) << endl; // AND
    cout << (a | b) << endl; // OR
    cout << (a ^ b) << endl; // XOR
    cout << (~a) << endl;    // NOT
    cout << (a << 1) << endl;// shift left
    cout << (a >> 1) << endl;// shift right
}