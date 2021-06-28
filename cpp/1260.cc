#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int kMaxN = 1000;

int n, m, v;
vector<vector<bool>> graph(kMaxN + 1, vector<bool>(kMaxN + 1));
vector<bool> visited(kMaxN + 1);

void DFS(int v) {
  cout << v << " ";
  visited[v] = true;
  for (int i = 1; i <= n; ++i) { if (graph[v][i] && !visited[i]) { DFS(i); } }
}

void BFS(int v) {
  queue<int> q;
  q.push(v);
  visited[v] = true;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    cout << v << " ";
    for (int i = 1; i <= n; ++i) {
      if (graph[v][i] && !visited[i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

int main() {
  cin >> n >> m >> v;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = true;
    graph[y][x] = true;
  }
  DFS(v);
  cout << "\n";
  visited.clear();
  visited.resize(kMaxN + 1);
  BFS(v);

  return 0;
}
