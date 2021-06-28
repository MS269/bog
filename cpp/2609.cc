#include <iostream>

using namespace std;

int GCD(int a, int b) {
  while (b != 0) {
    int n = a % b;
    a = b;
    b = n;
  }
  return a;
}

int main() {
  int num1, num2;
  cin >> num1 >> num2;
  cout << GCD(num1, num2) << "\n";
  cout << num1 * num2 / GCD(num1, num2) << "\n";

  return 0;
}
