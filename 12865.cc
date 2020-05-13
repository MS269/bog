#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> vec(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> vec[i].first >> vec[i].second;
  vector<int> dp(k + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = k; j >= 1; j--) {
      if (vec[i].first <= j)
        dp[j] = max(dp[j], dp[j - vec[i].first] + vec[i].second);
    }
  }
  cout << dp[k];

  return 0;
}
