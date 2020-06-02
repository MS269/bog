#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll kMod = 1000000007;

ll x, y, temp;

void Euclidean(ll b, ll p) {
  if (b % p > 0) {
    Euclidean(p, b % p);
    temp = y;
    y = x - (b / p) * y;
    x = temp;
  } else {
    x = 0;
    y = 1;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> fact(n + 1, 1);
  for (int i = 2; i <= n; ++i) { fact[i] = (fact[i - 1] * i) % kMod; }
  Euclidean(kMod, (fact[n - k] * fact[k]) % kMod);
  ll rslt = (fact[n] * (y % kMod)) % kMod;
  if (rslt < 0) { rslt += kMod; }
  cout << rslt;

  return 0;
}
