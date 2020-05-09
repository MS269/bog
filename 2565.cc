#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> line(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> line[i].first >> line[i].second;
  sort(line.begin(), line.end());
  vector<int> dp(n + 1);
  int max_cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (line[i].second > line[j].second && dp[i] <= dp[j])
        dp[i] = dp[j] + 1;
    }
    max_cnt = max(max_cnt, dp[i]);
  }
  cout << n - max_cnt;

  return 0;
}
