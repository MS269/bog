#include <iostream>
#include <vector>
//#include <utility>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <limits>

using namespace std;

//using ll = long long;

const int kMax = 40;

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
  vector<int> memo(kMax + 1);
  memo[0] = 0;
  memo[1] = 1;
  for (int i = 2; i <= kMax; i++)
    memo[i] = memo[i - 1] + memo[i - 2];
  int n;
  while (t--) {
    cin >> n;
    if (n == 0)
      cout << 1 << " " << 0 << "\n";
    else
      cout << memo[n - 1] << " " << memo[n] << "\n";
  }

  return 0;
}
