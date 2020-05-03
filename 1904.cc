#include <iostream>
#include <vector>
//#include <utility>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <limits>

using namespace std;

//using ll = long long;

const int kMod = 15746;

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

  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++)
    dp[i] = (dp[i - 1] + dp[i - 2]) % kMod;
  cout << dp[n];

  return 0;
}
