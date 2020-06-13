#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

const int kMod = 1e6;
const int kPeriod = kMod * 1.5;

int main() {
  ll n;
  cin >> n;
  vl fib;
  fib.push_back(0);
  fib.push_back(1);
  for (int i = 2; i < kPeriod; ++i) {
    fib.push_back((fib[i - 1] + fib[i - 2]) % kMod);
  }
  cout << fib[n % kPeriod];

  return 0;
}
