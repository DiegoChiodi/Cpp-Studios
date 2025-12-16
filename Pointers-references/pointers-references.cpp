#include <iostream>

int main() {
    int x = 16;
    int* p = &x;

    std::cout << "x =  " << x << std::endl;
    std::cout << "&x = " << &x << std::endl;
    std::cout << "p =  " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;

    
    *p = 1;
    std::cout << "*p alterado" << std::endl;
    
    std::cout << "*p = " << *p << std::endl;
}