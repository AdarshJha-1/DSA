#include <iostream>
#include <vector>

using namespace std;

int sumOfArr(vector<int> &weights) {
  int sum = 0;
  for (auto it : weights) {
    sum += it;
  }
  return sum;
}

bool isPossible(vector<int> &weights, int mid, int days) {
  int canCarryWeight = 0;
  int daysTaken = 1;
  for (int i = 0; i < weights.size(); i++) {
    if (canCarryWeight + weights[i] > mid) {
      daysTaken++;
      canCarryWeight = weights[i];
      if (weights[i] > mid)
        return false;
    } else {
      canCarryWeight += weights[i];
    }
  }
  return daysTaken <= days;
}

int shipWithinDays(vector<int> &weights, int days) {
  int start = 1;
  int end = sumOfArr(weights);

  while (start < end) {
    int mid = start + (end - start) / 2;
    if (isPossible(weights, mid, days)) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return end;
}

int main() {
  vector<int> weights = {3, 2, 2, 4, 1, 4};
  int days = 3;
  cout << shipWithinDays(weights, days);
  return 0;
}
