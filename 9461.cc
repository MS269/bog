#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int kMax = 100;

int main() {
  int t;
  cin >> t;
  vector<ll> dp(kMax + 1, 1);
  for (int i = 4; i <= kMax; i++)
    dp[i] = dp[i - 3] + dp[i - 2];
  while (t--) {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
  }

  return 0;
}
