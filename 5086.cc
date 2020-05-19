#include <iostream>

using namespace std;

bool factor(int a, int b) {
  if (b % a == 0)
    return true;
  return false;
}

bool multiple(int a, int b) {
  if (a % b == 0)
    return true;
  return false;
}

int main() {
  while (true) {
    int num1, num2;
    cin >> num1 >> num2;
    if (num1 == 0 || num2 == 0)
      break;
    if (factor(num1, num2)) {
      cout << "factor" << "\n";
    } else if (multiple(num1, num2)) {
      cout << "multiple" << "\n";
    } else {
      cout << "neither" << "\n";
    }
  }

  return 0;
}
