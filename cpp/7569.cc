#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;

const vector<int> dz = {0, 0, 0, 0, 1, -1};
const vector<int> dy = {0, 0, 1, -1, 0, 0};
const vector<int> dx = {1, -1, 0, 0, 0, 0};

int main() {
  int m, n, h;
  cin >> m >> n >> h;
  vector<vector<vector<int>>> tomatoes(h, vector<vector<int>>(n, vector<int>(m)));
  queue<vector<int>> q;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        cin >> tomatoes[i][j][k];
        if (tomatoes[i][j][k] == 1) { q.push({i, j, k}); }
      }
    }
  }
  while (!q.empty()) {
    auto f = q.front();
    int z = f[0], y = f[1], x = f[2];
    q.pop();
    for (int i = 0; i < 6; ++i) {
      int nz = z + dz[i], ny = y + dy[i], nx = x + dx[i];
      if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) { continue; }
      if (tomatoes[nz][ny][nx] == 0) {
        tomatoes[nz][ny][nx] = tomatoes[z][y][x] + 1;
        q.push({nz, ny, nx});
      }
    }
  }
  int max_day = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (tomatoes[i][j][k] == 0) {
          cout << "-1 \n";
          return 0;
        }
        max_day = max(max_day, tomatoes[i][j][k]);
      }
    }
  }
  cout << max_day - 1 << '\n';

  return 0;
}
