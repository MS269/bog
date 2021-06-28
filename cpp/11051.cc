#include <iostream>
#include <vector>

using namespace std;

const int kMod = 10007;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i == j || j == 0) { continue; }
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % kMod;
    }
  }
  cout << dp[n][k];

  return 0;
}
