#include <iostream>

using namespace std;

int powerOf2(int n) {
  if (n == 0)
    return 1;
  return 2 * powerOf2(n - 1);
}

int main() {
  int n = 10;
  cout << powerOf2(n);
  return 0;
}
