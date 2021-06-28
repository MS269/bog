#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, temp, cnt = 0;
  cin >> n;
  vector<int> lis;
  lis.push_back(0);
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    if (temp > lis.back()) {
      lis.push_back(temp);
      ++cnt;
    } else {
      auto low = lower_bound(lis.begin(), lis.end(), temp);
      *low = temp;
    }
  }
  cout << cnt;

  return 0;
}
