#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> scores(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> scores[i];
  vector<int> dp(n + 1);
  dp[1] = scores[1];
  dp[2] = max(scores[1] + scores[2], scores[2]);
  dp[3] = max(scores[1] + scores[3], scores[2] + scores[3]);
  for (int i = 4; i <= n; i++)
    dp[i] = max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]);
  cout << dp[n];

  return 0;
}
