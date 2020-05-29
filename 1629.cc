#include <iostream>

using namespace std;

using ll = long long;

ll a, b, c;

ll Power(ll expo) {
  if (expo == 1) { return a % c; }
  ll ret = Power(expo >> 1);
  ret %= c;
  ret = (ret * ret) % c;
  if (expo % 2 == 0) { return ret; }
  return (ret * (a % c)) % c;
}

int main() {
  cin >> a >> b >> c;
  cout << Power(b);

  return 0;
}
