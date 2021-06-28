#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];
  sort(p.begin(), p.end());
  for (int i = 1; i < n; ++i)
    p[i] += p[i - 1];
  int sum = 0;
  for (auto a : p)
    sum += a;
  cout << sum;

  return 0;
}
