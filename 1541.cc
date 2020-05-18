#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int rslt = 0;
  string num;
  bool negative = false;
  for (int i = 0; i <= s.size(); ++i) {
    switch (s[i]) {
      case '+': case '-': case '\0':
        if (negative)
          rslt -= stoi(num);
        else
          rslt += stoi(num);
        num.clear();
        if (s[i] == '-')
          negative = true;
        break;
      default:
        num += s[i];
        break;
    }
  }
  cout << rslt;

  return 0;
}
