#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string p, ary;
    int n;
    cin >> p >> n >> ary;
    deque<int> dq;
    string num;
    for (auto a : ary) {
      switch (a) {
        case '[': break;
        case ',':
          dq.push_back(stoi(num));
          num = "";
          break;
        case ']':
          if (!num.empty()) { dq.push_back(stoi(num)); }
          break;
        default:
          num.push_back(a);
          break;
      }
    }
    bool reverse = false;
    bool error = false;
    for (auto a : p) {
      if (a == 'R') {
        reverse = !reverse;
      } else if (a == 'D') {
        if (dq.empty()) {
          error = true;
          break;
        }
        if (reverse) { dq.pop_back(); }
        else { dq.pop_front(); }
      }
    }
    if (error) {
      cout << "error\n";
    } else {
      cout << "[";
      if (reverse) {
        while (!dq.empty()) {
          cout << dq.back();
          dq.pop_back();
          if (!dq.empty()) { cout << ","; }
        }
      } else {
        while (!dq.empty()) {
          cout << dq.front();
          dq.pop_front();
          if (!dq.empty()) { cout << ","; }
        }
      }
      cout << "]\n";
    }
  }

  return 0;
}
