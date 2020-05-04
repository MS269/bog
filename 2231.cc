#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int min_constructor = 0;
  for (int i = 1; i < n; i++) {
    int decomposition = i;
    int constructor = i;
    while (constructor != 0) {
      decomposition += constructor % 10;
      constructor /= 10;
    }
    if (decomposition == n) {
      min_constructor = i;
      break;
    }
  }
  cout << min_constructor;

  return 0;
}
