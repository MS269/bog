#include <iostream>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;
      q.push({i, num});
      pq.push(num);
    }
    int cnt = 0;
    while (!q.empty()) {
      int idx = q.front().first;
      int val = q.front().second;
      q.pop();
      if (pq.top() == val) {
        pq.pop();
        ++cnt;
        if (idx == m) {
          cout << cnt << "\n";
          break;
        }
      } else {
        q.push({idx, val});
      }
    }
  }

  return 0;
}
