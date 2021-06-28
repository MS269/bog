#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  int title = 665;
  while (cnt != n) {
    title++;
    string s = to_string(title);
    if (s.find("666") != string::npos)
      cnt++;
  }
  cout << title;

  return 0;
}
