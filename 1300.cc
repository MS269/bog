#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int low = 1, high = k, rslt = 0;
  while (low <= high) {
    int mid = (low + high) / 2, cnt = 0;
    for (int i = 1; i <= n; ++i) { cnt += min(mid / i, n); }
    if (cnt < k) {
      low = mid + 1;
    } else {
      rslt = mid;
      high = mid - 1;
    }
  }
  cout << rslt;

  return 0;
}
