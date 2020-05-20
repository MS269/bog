#include <iostream>
#include <vector>

using namespace std;

const int kMax = 40;

int main() {
  int t;
  cin >> t;
  vector<int> dp(kMax + 1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= kMax; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  while (t--) {
    int n;
    cin >> n;
    if (n == 0)
      cout << 1 << " " << 0 << "\n";
    else
      cout << dp[n - 1] << " " << dp[n] << "\n";
  }

  return 0;
}
