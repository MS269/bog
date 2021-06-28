#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, temp;
vector<int> a;

void FindNum(int front, int back) {
  if (front > back) {
    cout << "0\n";
    return;
  }
  int mid = (front + back) / 2;
  if (temp > a[mid]) {
    FindNum(mid + 1, back);
  } else if (temp < a[mid]) {
    FindNum(0, mid - 1);
  } else {
    cout << "1\n";
  }
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  sort(a.begin(), a.end());
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> temp;
    FindNum(0, n - 1);
  }

  return 0;
}
