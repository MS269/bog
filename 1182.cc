#include <iostream>
#include <vector>
//#include <string>
//#include <utility>
//#include <algorithm>
//#include <cmath>
//#include <climits>

using namespace std;
//using ll = long long;

int n, s;
vector<int> vec;
int subset_cnt = 0;

void GetSubsets(int cnt, int sum) {
  if (cnt == n) return;
  if (sum + vec[cnt] == s) subset_cnt++;
  GetSubsets(cnt + 1, sum);
  GetSubsets(cnt + 1, sum + vec[cnt]);
}

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

  cin >> n >> s;
  vec.resize(n);
  for (int i = 0; i < n; i++)
    cin >> vec[i];
  GetSubsets(0, 0);
  cout << subset_cnt;

  return 0;
}
