#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, house_cnt;
vector<string> map;
vector<vector<bool>> is_visited;
vector<int> complexes;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void DFS(int x, int y) {
  is_visited[x][y] = true;
  ++house_cnt;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) { continue; }
    if (!is_visited[nx][ny] && map[nx][ny] == '1') { DFS(nx, ny); }
  }
}

int main() {
  cin >> n;
  map.resize(n);
  is_visited.resize(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) { cin >> map[i]; }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!is_visited[i][j] && map[i][j] == '1') {
        house_cnt = 0;
        DFS(i, j);
        complexes.push_back(house_cnt);
      }
    }
  }
  sort(complexes.begin(), complexes.end());
  cout << complexes.size() << '\n';
  for (auto a : complexes) { cout << a << '\n'; }

  return 0;
}
