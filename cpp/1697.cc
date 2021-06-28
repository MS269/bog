#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int kMax = 100000;

int n, k;

int BFS() {
  queue<pair<int, int>> q;
  vector<bool> is_visited(kMax + 1);
  q.push({n ,0});
  is_visited[n] = 0;
  while (!q.empty()) {
    auto f = q.front();
    int x = f.first, t = f.second;
    q.pop();
    if (x == k) return t;
    vector<int> nx = {x * 2, x + 1, x - 1};
    for (int i = 0; i < 3; ++i) {
      if (nx[i] < 0 || nx[i] > kMax) continue;
      if (!is_visited[nx[i]]) {
        q.push({nx[i], t + 1});
        is_visited[nx[i]] = true;
      }
    }
  }
}

int main() {
  cin >> n >> k;
  cout << BFS() << '\n';

  return 0;
}
