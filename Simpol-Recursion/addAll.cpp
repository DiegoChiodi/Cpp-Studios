#include <iostream>

int addAll (int n) {
   if (n == 0) return n;
   return n + addAll(n - 1);
}

int main() {
   int x = 0;
   std::cin >> x;
   std::cout << addAll(x);
   return 0;
}