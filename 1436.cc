#include <iostream>
#include <string>
//#include <vector>
//#include <utility>
//#include <algorithm>
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
  int cnt = 0;
  int title = 665;
  string s;
  while (cnt != n) {
    title++;
    s = to_string(title);
    if (s.find("666") != string::npos)
      cnt++;
  }
  cout << title;

  return 0;
}
