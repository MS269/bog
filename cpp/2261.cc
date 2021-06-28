#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

using ll = long long;

const int kMax = 10000;
const int kMin = -kMax;

ll GetDist(pair<int, int> a, pair<int, int> b) {
  ll dx = (ll)b.first - a.first;
  ll dy = (ll)b.second - a.second;
  return dx * dx + dy * dy;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> coords(n);
  for (int i = 0; i < n; ++i) { cin >> coords[i].first >> coords[i].second; }
  sort(coords.begin(), coords.end());
  map<pair<int, int>, int> cands;
  cands[{coords[0].second, coords[0].first}] = 0;
  cands[{coords[1].second, coords[1].first}] = 0;
  ll ans = GetDist(coords[0], coords[1]);
  int pos = 0;
  for (int i = 2; i < n; ++i) {
    while (pos < i) {
      int dx = coords[i].first - coords[pos].first;
      if (dx * dx <= ans) { break; }
      cands.erase({coords[pos].second, coords[pos].first});
      ++pos;
    }
    ll dist = sqrt(ans);
    auto left = cands.lower_bound({coords[i].second - dist, kMin});
    auto right = cands.upper_bound({coords[i].second + dist, kMax});
    for (auto it = left; it != right; ++it) {
      ans = min(ans, GetDist({it->first.second, it->first.first}, coords[i]));
    }
    cands[{coords[i].second, coords[i].first}] = 0;
  }
  cout << ans;

  return 0;
}
