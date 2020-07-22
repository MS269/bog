#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> tree(n);
  for (int i = 0; i < n; ++i) { cin >> tree[i]; }
  ll low = 1, high = *max_element(tree.begin(), tree.end()), rslt = 0;
  while (low <= high) {
    ll mid = (low + high) / 2, cnt = 0;
    for (int i = 0; i < n; ++i) { cnt += max(tree[i] - mid, 0LL); }
    if (cnt >= m) {
      rslt = max(rslt, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << rslt;

  return 0;
}
