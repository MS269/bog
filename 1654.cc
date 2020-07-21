#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
  int k, n;
  cin >> k >> n;
  vector<ll> lan(k);
  for (int i = 0; i < k; ++i) { cin >> lan[i]; }
  ll low = 1, high = *max_element(lan.begin(), lan.end()), rslt = 0;
  while (low <= high) {
    ll mid = (low + high) / 2;
    int cnt = 0;
    for (int i = 0; i < k; ++i) { cnt += lan[i] / mid; }
    if (cnt >= n) {
      rslt = max(rslt, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << rslt;

  return 0;
}
