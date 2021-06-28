#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<int> dy = {1, -1, 0, 0}, dx = {0, 0, 1, -1};

int n, m;
vector<string> mt;

int BFS() {
  queue<vector<int>> q;
  vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2)));
  q.push({0, 0, 1});
  visited[0][0][1] = 1;
  while (!q.empty()) {
    auto f = q.front();
    int y = f[0], x = f[1], can_break = f[2];
    q.pop();
    if (y == n - 1 && x == m - 1) return visited[y][x][can_break];
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (mt[ny][nx] == '0' && visited[ny][nx][can_break] == 0) {
        visited[ny][nx][can_break] = visited[y][x][can_break] + 1;
        q.push({ny, nx, can_break});
      }
      if (mt[ny][nx] == '1' && can_break == 1) {
        visited[ny][nx][can_break - 1] = visited[y][x][can_break] + 1;
        q.push({ny, nx, can_break - 1});
      }
    }
  }  
  return -1;
}

int main() {
  mt.clear();
  cin >> n >> m;
  mt.resize(n);
  for (auto& i : mt) cin >> i;
  cout << BFS() << '\n';

  return 0;
}
