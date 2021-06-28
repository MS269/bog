#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<string> maze;
vector<vector<int>> path;
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

void BFS() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  path[0][0] = 1;
  while (!q.empty()) {
    auto f = q.front();
    int x = f.first, y = f.second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
      if (maze[nx][ny] == '1' && path[nx][ny] == 0) {
        q.push({nx, ny});
        path[nx][ny] = path[x][y] + 1;
      } else if (path[nx][ny] == 0) {
        path[nx][ny] = -1;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  maze.resize(n);
  path.resize(n, vector<int>(m));
  for (auto& a : maze) { cin >> a; }
  BFS();
  cout << path[n - 1][m - 1] << '\n';

  return 0;
}
