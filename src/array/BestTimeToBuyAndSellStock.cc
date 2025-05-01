#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maxProfitBF(vector<int> &prices) {
  int profit = 0;
  for (int i = 0; i < prices.size(); i++) {
    for (int j = i + 1; j < prices.size(); j++) {
      if (prices[j] > prices[i]) {
        profit = max(profit, (prices[j] - prices[i]));
      }
    }
  }
  return profit;
}

int maxProfit(vector<int> &prices) {
  int minPrice = INT_MAX;
  int profit = 0;

  for (int i = 0; i < prices.size() - 1; i++) {
    minPrice = min(minPrice, prices[i]);
    int currProfit = prices[i + 1] - minPrice;
    profit = max(profit, currProfit);
  }
  return profit;
}

int main() {
  vector<int> prices = {2, 4, 1};
  cout << maxProfit(prices) << endl;
  return 0;
}
