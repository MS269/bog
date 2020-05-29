#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> screen;
string rslt;

void QuadTree(int y, int x, int size) {
  bool white = false, black = false;
  for (int i = y; i < y + size; ++i) {
    for (int j = x; j < x + size; ++j) {
      if (screen[i][j] == '0') { white = true; }
      else if (screen[i][j] == '1') { black = true; }
    }
  }
  if (white && !black) {
    rslt.push_back('0');
  } else if (black && !white) {
    rslt.push_back('1');
  } else {
    rslt.push_back('(');
    size /= 2;
    QuadTree(y, x, size);
    QuadTree(y, x + size, size);
    QuadTree(y + size, x, size);
    QuadTree(y + size, x + size, size);
    rslt.push_back(')');
  }
}

int main() {
  cin >> n;
  screen.resize(n);
  for (int i = 0; i < n; ++i) { cin >> screen[i]; }
  QuadTree(0, 0, n);
  cout << rslt;

  return 0;
}
