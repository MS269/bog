#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> tri(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> tri[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
    }
  }
  cout << *max_element(tri[n].begin(), tri[n].end());

  return 0;
}
