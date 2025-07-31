#include <algorithm>
#include <iostream>
#include <vector>


// WRONG :() did not understand the problem

using namespace std;

int forward(vector<char> arr, int k, int i) {
  int f = 0;
  for(int j = i + 1; j < (k + i) && j < arr.size(); j++) {
    if(arr[j] == 'T') {
      f++;
    }
  }
  return f; 
}
int backward(vector<char> arr, int k, int i) {
  int b = 0;
  for(int j = i - 1; j > (i - k) && j >= 0; j--) {
    if(arr[j] == 'T') {
      b++;
    }
  }
  return b;
}

int findMaxThiefBF(vector<char> arr, int k) {
  int maxThief = 0;
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] == 'P') {
      if(i == 0) {
        maxThief = max(maxThief, forward(arr, k, i));
      }else if(i == arr.size() - 1) {
        maxThief = max(maxThief, backward(arr, k, i));
      } else {
        // forward k places
        int f = forward(arr, k, i);
        // backward k places
        int b = backward(arr, k, i);
        maxThief = max(maxThief, (f + b));
      }
    }
  }
  return maxThief;
}

int main() {
  vector<char> arr = {'P', 'T', 'T', 'P', 'T'};
  int k = 1;

  int ans = findMaxThiefBF(arr, k);
  cout << ans << endl;
  return 0;
}
