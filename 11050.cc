#include <iostream>

using namespace std;

int Fac(int a) {
  int fac = 1;
  for (int i = 2; i <= a; ++i) { fac *= i; }
  return fac;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << Fac(n) / Fac(k) / Fac(n - k);

  return 0;
}
