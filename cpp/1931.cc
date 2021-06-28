#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> conf(n);
  for (int i = 0; i < n; ++i)
    cin >> conf[i].first >> conf[i].second;
  sort(conf.begin(), conf.end(), Compare);
  int cnt = 0;
  int end = 0;
  for (int i = 0; i < n; ++i) {
    if (conf[i].first >= end) {
      end = conf[i].second;
      cnt++;
    }
  }
  cout << cnt;

  return 0;
}
