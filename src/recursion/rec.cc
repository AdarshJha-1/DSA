#include <iostream>

using namespace std;

void happyBirtdayDayLeft(int n) {
  if (n == 0) {
    cout << "Happy Birthday";
    return;
  }

  cout << n << " Days left for Birthday";
  cout << endl;
  happyBirtdayDayLeft(n - 1);
}

void print1toN(int n, int i) {
  if (i > n) {
    return;
  }
  cout << i << endl;
  print1toN(n, i + 1);
}

void print1toN(int n) {
  if (n == 0) {
    return;
  }
  print1toN(n - 1);
  cout << n << endl;
}

void printEven(int n) {
  if (n == 0) {
    return;
  }
  printEven(n - 1);
  if (n % 2 == 0) {
    cout << n << endl;
  }
}

int main() {
  print1toN(10);
  return 0;
}
