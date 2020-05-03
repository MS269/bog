#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
//#include <utility>
//#include <cmath>

using namespace std;
//using ll = long long;

vector<string> wbboard = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};
vector<string> bwboard = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};
vector<string> board;


int CheckWBBoard(int x, int y)
{
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[x + i][y + j] != wbboard[i][j])
        cnt++;
    }
  }
  return cnt;
}

int CheckBWBoard(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[x + i][y + j] != bwboard[i][j])
        cnt++;
    }
  }
  return cnt;
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

  int n, m;
  cin >> n >> m;
  board.resize(n);
  for (int i = 0; i < n; i++)
    cin >> board[i];
  int min_cnt = INT_MAX;
  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      min_cnt = min(min_cnt, CheckWBBoard(i, j));
      min_cnt = min(min_cnt, CheckBWBoard(i, j));
    }
  }
  cout << min_cnt;

  return 0;
}
