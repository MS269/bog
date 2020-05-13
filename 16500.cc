#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  int n;
  cin >> s >> n;
  vector<string> words(n + 1);
  for (int i = 0; i < n; ++i)
    cin >> words[i];
  vector<int> dp(s.size() + 1);
  dp[s.size()] = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    for (int j = 0; j <= n; j++) {
      if (s.find(words[j], i) == i && dp[i + words[j].size()] == 1) {
        dp[i] = 1;
        break;
      } else {
        dp[i] = 0;
      }
    }
  }
  cout << dp[0];

  return 0;
}
