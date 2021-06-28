#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using vl = vector<ll>;

int n;
vl h;

ll DivNConq(int left, int right) {
  if (left == right) { return h[left]; }
  int mid = (left + right) / 2;
  ll ret = max(DivNConq(left, mid), DivNConq(mid + 1, right));
  ll low = mid, high = (ll)mid + 1;
  ll height = min(h[low], h[high]);
  ret = max(ret, height * 2);
  while (left < low || high < right) {
    if (high < right && (low == left || h[low - 1] < h[high + 1])) {
      ++high;
      height = min(height, h[high]);
    } else {
      --low;
      height = min(height, h[low]);
    }
    ret = max(ret, height * (high - low + 1));
  }
  return ret;
}

int main() {
  while (true) {
    cin >> n;
    if (n == 0) { break; }
    h.resize(n);
    for (int i = 0; i < n; ++i) { cin >> h[i]; }
    cout << DivNConq(0, n - 1) << "\n";
  }

  return 0;
}
