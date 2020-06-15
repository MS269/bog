#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const int kMod = 1000;

vvl operator*(const vvl& a, const vvl& b) {
  ll s = a.size();
  vvl ret(s, vl(s));
  for (ll i = 0; i < s; ++i) {
    for (ll j = 0; j < s; ++j) {
      for (ll k = 0; k < s; ++k) {
        ret[i][j] += a[i][k] * b[k][j];
      }
      ret[i][j] %= kMod;
    }
  }
  return ret;
}

vvl Pow(vvl a, ll e) {
  ll s = a.size();
  vvl ret(s, vl(s));
  for (ll i = 0; i < s; ++i) { ret[i][i] = 1; }
  while (e > 0) {
    if (e % 2 == 1) { ret = ret * a; }
    e /= 2;
    a = a * a;
  }
  return ret;
}

int main() {
  int n;
  ll b;
  cin >> n >> b;
  vvl a(n, vl(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  a = Pow(a, b);
  for (auto i : a) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }

  return 0;
}
