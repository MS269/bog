#include <iostream>

using namespace std;

const int kMax = 10000;
const int kEmpty = -1;

class Stack {
 public:
  int stack[kMax];
  int top;

  Stack() { this->top = kEmpty; }

  void Push(int x) { this->stack[++top] = x; }

  int Pop() { 
    if (this->top > kEmpty) { return this->stack[this->top--]; }
    else { return -1; }
  }

  int Size() { return this->top + 1; }

  bool Empty() {
    if (this->top == kEmpty) { return true; }
    else { return false; }
  }

  int Top() {
    if (this->top > kEmpty) { return this->stack[this->top]; }
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
