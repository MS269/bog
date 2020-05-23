#include <iostream>

using namespace std;

const int kMax = 10000;
const int kEmpty = -1;

class Stack {
 public:
  int stack_[kMax];
  int top_;

  Stack() { top_ = kEmpty; }

  void Push(int x) { stack_[++top_] = x; }

  int Pop() { 
    if (top_ > kEmpty) { return stack_[top_--]; }
    else { return -1; }
  }

  int Size() { return top_ + 1; }

  bool Empty() {
    if (top_ == kEmpty) { return true; }
    else { return false; }
  }

  int Top() {
    if (top_ > kEmpty) { return stack_[top_]; }
    else { return -1; }
  }
};

Stack stack;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string command;
    cin >> command;
    if (command == "push") {
      int num;
      cin >> num;
      stack.Push(num);
    } else if (command == "pop") {
      cout << stack.Pop() << "\n";
    } else if (command == "size") {
      cout << stack.Size() << "\n";
    } else if (command == "empty") {
      if (stack.Empty()) { cout << 1 <<"\n"; }
      else { cout << 0 << "\n"; }
    } else if (command == "top") {
      cout << stack.Top() << "\n";
    }
  }

  return 0;
}
