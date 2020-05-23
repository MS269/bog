#include <iostream>

using namespace std;

const int kMax = 2e6;

class Queue {
 public:
  int queue_[kMax];
  int front_;
  int back_;

  Queue() {
    front_ = 0;
    back_ = -1;
  }

  void Push(int x) { queue_[++back_] = x; }

  int Pop() { 
    if (front_ <= back_) { return queue_[front_++]; }
    else { return -1; }
  }

  int Size() { return back_ - front_ + 1; }

  bool Empty() {
    if (front_ > back_) { return true; }
    else { return false; }
  }

  int Front() {
    if (front_ <= back_) { return queue_[front_]; }
    else { return -1; }
  }
  
  int Back() {
    if (front_ <= back_) { return queue_[back_]; }
    else { return -1; }
  }
};

Queue queue;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string command;
    cin >> command;
    if (command == "push") {
      int num;
      cin >> num;
      queue.Push(num);
    } else if (command == "pop") {
      cout << queue.Pop() << "\n";
    } else if (command == "size") {
      cout << queue.Size() << "\n";
    } else if (command == "empty") {
      if (queue.Empty()) { cout << 1 << "\n"; }
      else { cout << 0 << "\n"; }
    } else if (command == "front") {
      cout << queue.Front() << "\n";
    } else if (command == "back") {
      cout << queue.Back() << "\n";
    }
  }

  return 0;
}
