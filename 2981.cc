#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; ++i) { cin >> vec[i]; }
  sort(vec.begin(), vec.end());
  int m = vec[1] - vec[0];
  for (int i = 2; i < n; ++i) { m = GCD(m, vec[i] - vec[i - 1]); }
  vector<int> fac;
  for (int i = 2; i * i <= m; ++i) {
    if (m % i == 0) {
      fac.push_back(i);
      fac.push_back(m / i);
    }
  }
  fac.push_back(m);
  sort(fac.begin(), fac.end());
  fac.erase(unique(fac.begin(), fac.end()), fac.end());
  for (auto a : fac) { cout << a << " "; }

  return 0;
}
