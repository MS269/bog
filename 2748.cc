#include <iostream>
#include <vector>
//#include <string>
//#include <utility>
//#include <algorithm>
//#include <cmath>
//#include <limits>

using namespace std;

using ll = long long;

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
  vector<ll> memo(n + 1);
  memo[0] = 0;
  memo[1] = 1;
  for (int i = 2; i <= n; i++)
    memo[i] = memo[i - 1] + memo[i - 2];
  cout << memo[n];

  return 0;
}
