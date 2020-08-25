#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> heights(500, vector<int>(500)), dp(500, vector<int>(500, -1));
vector<int> dy = {1, -1, 0, 0}, dx = {0, 0, 1, -1};

int DFS(int y, int x) {
  if (dp[y][x] != -1) { return dp[y][x]; }
  if (y == m - 1 && x == n - 1) { return 1; }
  dp[y][x] = 0;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny < 0 || ny >= m || nx < 0 || nx >= n) { continue; }
    if (heights[ny][nx] < heights[y][x]) { dp[y][x] += DFS(ny, nx); }
  }
  return dp[y][x];
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) { for (int j = 0; j < n; ++j) { cin >> heights[i][j]; } }
  cout << DFS(0, 0);

  return 0;
}
