#include <iostream>

using namespace std;

int sumNNum(int n) {
  if (n == 1)
    return 1;
  return n + sumNNum(n - 1);
}

int main() {
  int n = 6;
  cout << sumNNum(n);
  return 0;
}
