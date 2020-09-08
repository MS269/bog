#include <iostream>
#include <vector>

using namespace std;

int m, n, k;
vector<vector<bool>> cabbages;
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

void DFS(int x, int y) {
  cabbages[x][y] = false;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= m || ny < 0 || ny >= n) { continue; }
    if (cabbages[nx][ny]) { DFS(nx, ny); }
  }
}

void TestCase() {
  cin >> m >> n >> k;
  cabbages.resize(m, vector<bool>(n));
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    cabbages[x][y] = true;
  }
  int worm_cnt = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (cabbages[i][j]) {
        DFS(i, j);
        ++worm_cnt;
      }
    }
  }
  cout << worm_cnt << '\n';
  cabbages.clear();
}

int main() {
  int t;
  cin >> t;
  while (t--) { TestCase(); }

  return 0;
}
