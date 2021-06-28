#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

pair<int, int> CntExp(ll a) {
  ll exp2 = 0, exp5 = 0;
  for (ll i = 2; i <= a; i *= 2) { exp2 += a / i; }
  for (ll i = 5; i <= a; i *= 5) { exp5 += a / i; }
  return {exp2, exp5};
}

int main() {
  ll n, m;
  cin >> n >> m;
  auto numerator = CntExp(n);
  auto denominator1 = CntExp(m);
  auto denominator2 = CntExp(n - m);
  int exp2 = numerator.first - denominator1.first - denominator2.first;
  int exp5 = numerator.second - denominator1.second - denominator2.second;
  cout << min(exp2, exp5);

  return 0;
}
