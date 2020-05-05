#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int kMod = 1000000000;

int main() {
  int n;
  cin >> n;
  vector<vector<ll>> dp(n + 1, vector<ll>(11));
  for (int i = 1; i <= 9; i++)
    dp[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = dp[i - 1][1];
    for (int j = 1; j <= 9; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % kMod;
    }
  }
  ll sum = 0;
  for (auto a : dp[n])
    sum += a;
  cout << sum % kMod;

  return 0;
}
