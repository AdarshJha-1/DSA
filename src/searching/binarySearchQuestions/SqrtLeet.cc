#include <iostream>

using namespace std;

int mySqrt(int x) {
  int start = 1;
  int end = x;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (mid == x / mid) {
      return mid;
    } else if (mid > x / mid) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return end;
}

int main() {
  int x = 8;
  cout << mySqrt(x);
}
