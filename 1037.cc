#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int cnt;
  cin >> cnt;
  vector<int> fac(cnt);
  for (int i = 0; i < cnt; ++i)
    cin >> fac[i];
  auto min_max_fac = minmax_element(fac.begin(), fac.end());
  cout << *min_max_fac.first * *min_max_fac.second;

  return 0;
}
