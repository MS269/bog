#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int fac = 2;
  while (n != 1) {
    if (n % fac == 0) {
      n /= fac;
      cout << fac << "\n";
    } else {
      ++fac;
    }
  }

  return 0;
}
