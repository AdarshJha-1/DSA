#include <iostream>

using namespace std;

int sumOfSqrN(int n) {
  if (n == 1)
    return 1;
  return n * n + sumOfSqrN(n - 1);
}

int main() {
  int n = 4;
  cout << sumOfSqrN(n);
  return 0;
}
