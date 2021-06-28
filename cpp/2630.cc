#include <iostream>
#include <vector>

using namespace std;

int n, w, b;
vector<vector<int>> paper;

void QuadTree(int x, int y, int size) {
  int cnt = 0;
  for (int i = x; i < x + size; ++i) {
    for (int j = y; j < y + size; ++j) {
      if (paper[i][j] == 1) { ++cnt; }
    }
  }
  if (cnt == 0) {
    ++w;
  } else if (cnt == size * size) {
    ++b;
  } else {
    size /= 2;
    QuadTree(x, y, size);
    QuadTree(x, y + size, size);
    QuadTree(x + size, y, size);
    QuadTree(x + size, y + size, size);
  }
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
  QuadTree(0, 0, n);
  cout << w << "\n";
  cout << b << "\n";

  return 0;
}
