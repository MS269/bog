#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; ++i) { cin >> vec[i]; }
  stack<int> seq;
  vector<char> op;
  auto iter = vec.begin();
  for (int i = 1; i <= n; ++i) {
    seq.push(i);
    op.push_back('+');
    while (!seq.empty()) {
      if (*iter != seq.top()) {
        break;
      } else {
        seq.pop();
        op.push_back('-');
        ++iter;
      }
    }
  }
  if (seq.empty()) { for (auto a : op) { cout << a << "\n"; } }
  else { cout << "NO"; }

  return 0;
}
