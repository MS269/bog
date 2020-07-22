#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) { cin >> x[i]; }
  sort(x.begin(), x.end());
  int low = 1, high = x[n - 1] - x[0], rslt = 0;
  while (low <= high) {
    int mid = (low + high) / 2, cnt = 1, prev = 0;
    for (int i = 1; i < n; ++i) {
      if (x[i] - x[prev] >= mid) {
        ++cnt;
        prev = i;
      }
    }
    if (cnt >= c) {
      rslt = max(rslt, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << rslt;

  return 0;
}
