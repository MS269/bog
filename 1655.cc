#include <iostream>
#include <queue>

using namespace std;

int main() {
#ifndef FASTIO
#define FASTIO
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif // FASTIO

  int n, temp;
  cin >> n;
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    if (max_heap.empty()) {
      max_heap.push(temp);
    } else if (max_heap.size() == min_heap.size()) {
      max_heap.push(temp);
    } else {
      min_heap.push(temp);
    }
    if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
      int a = max_heap.top();
      int b = min_heap.top();
      max_heap.pop();
      min_heap.pop();
      max_heap.push(b);
      min_heap.push(a);
    }
    cout << max_heap.top() << "\n";
  }

  return 0;
}
