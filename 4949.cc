#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  while (true) {
    string s;
    getline(cin, s);
    if (s == ".") { break; }
    stack<char> stk;
    bool is_balanced = true;
    for (auto a : s) {
      if (a == '(' || a == '[') {
        stk.push(a);
      } else if (a == ')') {
        if (!stk.empty() && stk.top() == '(') {
          stk.pop();
        } else {
          is_balanced = false;
          break;
        }
      } else if (a == ']') {
        if (!stk.empty() && stk.top() == '[') {
          stk.pop();
        } else {
          is_balanced = false;
          break;
        }
      }
    }
    if (is_balanced && stk.empty()) { cout << "yes\n"; }
    else { cout << "no\n"; }
  }

  return 0;
}
