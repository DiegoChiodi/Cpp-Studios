#include <iostream>

int coin(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    std::cout << n << "     " <<coin(n - 1) << "       " << coin(n - 2)<< std::endl;

    return coin(n - 1) + coin(n - 2); // usando moedas de 1 e 2
}

int main () {
    int x = 0;
    std::cin >> x;
    std::cout << coin(x);
    return 0;
}