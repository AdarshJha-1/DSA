#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maxInArr(vector<int> &piles) {
  int maxNum = INT_MIN;
  for (int i = 0; i < piles.size(); i++) {
    maxNum = max(maxNum, piles[i]);
  }
  return maxNum;
}

bool canEatAll(vector<int> &piles, int mid, int h) {
  int hTaken = 0;
  for (int i = 0; i < piles.size(); i++) {
    hTaken += piles[i] / mid;
    if (piles[i] % mid != 0) {
      hTaken++;
    }

    if (hTaken > h) {
      return false;
    }
  }
  return true;
}

int minEatingSpeed(vector<int> &piles, int h) {
  int start = 1;
  int end = maxInArr(piles);
  while (start < end) {
    int mid = start + (end - start) / 2;
    if (canEatAll(piles, mid, h)) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return start;
}

int main() {
  vector<int> piles = {30, 11, 23, 4, 20};
  int h = 5;
  cout << minEatingSpeed(piles, h);
  return 0;
}
