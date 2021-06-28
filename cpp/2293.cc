#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> values(n + 1);
  for (int i = 1; i <= n; ++i) { cin >> values[i]; }
  vector<int> dp(k + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (j >= values[i]) { dp[j] += dp[j - values[i]]; }
    }
  }
  cout << dp[k];

  return 0;
}
