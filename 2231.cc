#include <iostream>
#include <algorithm>
//#include <climits>
//#include <vector>
//#include <string>
//#include <utility>
//#include <cmath>

using namespace std;
//using ll = long long;

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
  int min_constructor = 0;
  int decomposition;
  int constructor;
  for (int i = 1; i < n; i++) {
    decomposition = i;
    constructor = i;
    while (constructor != 0) {
      decomposition += constructor % 10;
      constructor /= 10;
    }
    if (decomposition == n) {
      min_constructor = i;
      break;
    }
  }
  cout << min_constructor;

  return 0;
}
