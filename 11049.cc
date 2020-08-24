#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

const int kMax = 987654321;

vector<pair<int, int>> sizes;
vector<vector<int>> dp(500, vector<int>(500, -1));

int RF(int left, int right) {
  if (left == right) { return 0; }
  int min_num = kMax;
  if (dp[left][right] != -1) { return dp[left][right]; }
  for (int i = left; i < right; ++i) {
    min_num = min(min_num
      , RF(left, i) + RF(i + 1, right)
      + sizes[left].first * sizes[i].second * sizes[right].second);
  }
  dp[left][right] = min_num;
  return dp[left][right];
}

int main() {
  int n;
  cin >> n;
  sizes.resize(n);
  for (int i = 0; i < n; ++i) { cin >> sizes[i].first >> sizes[i].second; }
  cout << RF(0, n - 1);

  return 0;
}
