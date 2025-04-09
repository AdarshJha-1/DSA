#include <iostream>
#include <vector>

using namespace std;

int sum3v1(vector<int> arr, int x) {
  for(int i = 0; i < arr.size() - 2; i++) {
    for(int j  = i + 1; j < arr.size() - 1; j++ )  {
      for(int k = j + 1; k < arr.size(); k++) {
	if(arr[i] + arr[j] + arr[k] == x) {
	  return 1;
	}
      }
    }
  }
  return 0;
}

int main() {
  vector<int> arr = {1,4,45,6,10,8};
  int x = 13;
  int ans = sum3v1(arr, x); 
  cout << ans << endl;
  return 0;
}
