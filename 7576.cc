#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> tomatoes(n, vector<int>(m));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> tomatoes[i][j];
      if (tomatoes[i][j] == 1) { q.push({i, j}); }
    }
  }
  while (!q.empty()) {
    auto f = q.front();
    int x = f.first, y = f.second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
      if (tomatoes[nx][ny] == 0) {
        tomatoes[nx][ny] = tomatoes[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  int max_day = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (tomatoes[i][j] == 0) {
        cout << "-1 \n";
        return 0;
      }
      max_day = max(max_day, tomatoes[i][j]);
    }
  }
  cout << max_day - 1 << '\n';

  return 0;
}
