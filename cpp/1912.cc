#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> vec[i];
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++)
    dp[i] = max(dp[i - 1] + vec[i], vec[i]);
  cout << *max_element(dp.begin() + 1, dp.end());

  return 0;
}
