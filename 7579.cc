#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kMax = 987654321;
const int kMaxCost = 10000;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> bytes(n), costs(n);
  for (int i = 0; i < n; ++i) { cin >> bytes[i]; }
  for (int i = 0; i < n; ++i) { cin >> costs[i]; }
  int ans = kMax;
  vector<vector<int>> dp(n, vector<int>(kMaxCost + 1));
  dp[0][costs[0]] = bytes[0];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= kMaxCost; ++j) {
      if (j - costs[i] >= 0) { dp[i][j] = dp[i - 1][j - costs[i]] + bytes[i]; }
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (dp[i][j] >= m) { ans = min(ans, j); }
    }
  }
  cout << ans;

  return 0;
}
