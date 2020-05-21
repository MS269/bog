#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

int main() {
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) { cin >> r[i]; }
  for (int i = 1; i < n; ++i) {
    int gcd = GCD(r[0], r[i]);
    cout << r[0] / gcd << "/" << r[i] / gcd << "\n";
  }

  return 0;
}
