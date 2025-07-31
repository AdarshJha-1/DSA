#include "iostream"

using namespace std;

int climbStairs(int n) {
  if(n == 1 || n == 2 || n == 3) return n;
  return climbStairs(n - 1) + climbStairs(n - 2);
}

int main (int argc, char *argv[]) {
  int n = 40;
  cout << climbStairs(n);
  return 0;
}
