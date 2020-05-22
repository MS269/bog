#include <iostream>
#include <stack>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string ps;
    cin >> ps;
    stack<char> stk;
    for (auto a : ps) {
      if (a == '(' || stk.empty()) { stk.push(a); }
      else if (stk.top() == '(') { stk.pop(); }
    }
    if (stk.empty()) { cout << "YES\n"; }
    else { cout << "NO\n"; }
  }

  return 0;
}
