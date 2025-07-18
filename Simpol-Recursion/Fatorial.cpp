#include <iostream>

int fatorial (int n) {
   if (n <= 1) return n;
   return n * fatorial(n - 1);
}

int main() {
   int x = 0;
   std::cin >> x;
   std::cout << fatorial(x);
   std::cout << addAll(x);
   return 0;
}