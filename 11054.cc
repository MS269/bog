#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j <= n; j++) {
      if (a[i] > a[j])
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  vector<int> r_dp(n + 1);
  for (int i = n; i >= 1; i--) {
    r_dp[i] = 1;
    for (int j = n; j >= i; j--) {
      if (a[i] > a[j])
        r_dp[i] = max(r_dp[i], r_dp[j] + 1);
    }
  }
  int max_len = 0;
  for (int i = 1; i <= n; i++)
    max_len = max(max_len, dp[i] + r_dp[i] - 1);
  cout << max_len;

  return 0;
}
