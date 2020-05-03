#include <iostream>
#include <vector>
//#include <utility>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <limits>

using namespace std;

using ll = long long;

const int kMax = 100;

int main() {
#define DEBUG
#ifndef DEBUG
#define DEBUG
  FILE* stream;
  freopen_s(&stream, "input.txt", "r", stdin);
  freopen_s(&stream, "output.txt", "w", stdout);
#endif // DEBUG

//#define FASTIO
#ifndef FASTIO
#define FASTIO
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif // FASTIO

  int t;
  cin >> t;
  vector<ll> dp(kMax + 1, 1);
  for (int i = 4; i <= kMax; i++)
    dp[i] = dp[i - 3] + dp[i - 2];
  int n;
  while (t--) {
    cin >> n;
    cout << dp[n] << "\n";
  }

  return 0;
}
