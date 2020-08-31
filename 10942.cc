#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef FASTIO
#define FASTIO
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif // FASTIO

  int n, m;
  cin >> n;
  vector<int> nums(n + 1);
  for (int i = 1; i <= n; ++i) { cin >> nums[i]; }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = 1;
    if (nums[i] == nums[i - 1]) { dp[i - 1][i] = 1; }
  }
  for (int i = 2; i < n; ++i) {
    for (int j = 1; j <= n - i; ++j) {
      int k = i + j;
      if (nums[j] == nums[k] && dp[j + 1][k - 1] == 1) { dp[j][k] = 1; }
    }
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int s, e;
    cin >> s >> e;
    cout << dp[s][e] << "\n";
  }

  return 0;
}
