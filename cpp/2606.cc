#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 100;

int n, m, cnt;
vector<vector<bool>> network(kMaxN + 1, vector<bool>(kMaxN + 1));
vector<bool> is_visited(kMaxN + 1);

void DFS(int v) {
  is_visited[v] = true;
  for (int i = 1; i <= n; ++i) {
    if (!is_visited[i] && network[v][i]) {
      ++cnt;
      DFS(i);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    network[x][y] = true;
    network[y][x] = true;
  }
  DFS(1);
  cout << cnt;

  return 0;
}
