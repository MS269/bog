#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> dp(n + 1);
  for (int i = 2; i <= n; ++i) {
    dp[i].first = dp[i - 1].first;
    dp[i].second = dp[i - 1].second;
    for (int j = i; j % 2 == 0; j /= 2) { ++dp[i].first; }
    for (int j = i; j % 5 == 0; j /= 5) { ++dp[i].second; }
  }
  cout << min(dp[n].first, dp[n].second);

  return 0;
}
