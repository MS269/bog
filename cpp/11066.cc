#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int kMax = 987654321;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    vector<int> files(k + 1);
    vector<int> sums(k + 1);
    for (int i = 1; i <= k; ++i) {
      cin >> files[i];
      sums[i] = sums[i - 1] + files[i];
    }
    vector<vector<int>> nums(k + 1, vector<int>(k + 1));
    vector<vector<int>> dp(k + 1, vector<int>(k + 1));
    for (int i = 1; i <= k; ++i) { nums[i - 1][i] = i; }
    for (int d = 2; d <= k; ++d) {
      for (int x = 0; x + d <= k; ++x) {
        int y = x + d;
        dp[x][y] = kMax;
        for (int z = nums[x][y - 1]; z <= nums[x + 1][y]; z++) {
          int v = dp[x][z] + dp[z][y] + sums[y] - sums[x];
          if (dp[x][y] > v) {
            dp[x][y] = v;
            nums[x][y] = z;
          }
        }
      }
    }
    cout << dp[0][k] << "\n";
  }

  return 0;
}
