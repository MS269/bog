#include <iostream>
#include <vector>

using namespace std;

int n, minus_cnt, zero_cnt, plus_cnt;
vector<vector<int>> paper;

void DivConq(int y, int x, int size) {
  for (int i = y; i < y + size; ++i) {
    for (int j = x; j < x + size; ++j) {
      if (paper[i][j] != paper[y][x]) {
        size /= 3;
        for (int k = 0; k < 3; ++k) {
          for (int l = 0; l < 3; ++l) {
            DivConq(y + k * size, x + l * size, size);
          }
        }
        return;
      }
    }
  }
  if (paper[y][x] == -1) { ++minus_cnt; }
  else if (paper[y][x] == 0) { ++zero_cnt; }
  else if (paper[y][x] == 1) { ++plus_cnt; }
}

int main() {
  cin >> n;
  paper.resize(n);
  for (int i = 0; i < n; ++i) {
    paper[i].resize(n);
    for (int j = 0; j < n; ++j) {
      cin >> paper[i][j];
    }
  }
  DivConq(0, 0, n);
  cout << minus_cnt << "\n";
  cout << zero_cnt << "\n";
  cout << plus_cnt << "\n";

  return 0;
}
