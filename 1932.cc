#include <iostream>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <string>
//#include <cmath>
//#include <limits>

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
  vector<vector<int>> tri(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> tri[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
    }
  }
  cout << *max_element(tri[n].begin(), tri[n].end());

  return 0;
}
