#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  cin >> m >> k;
  vector<vector<int>> b(m, vector<int>(k));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> b[i][j];
    }
  }
  vector<vector<int>> ab(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      for (int l = 0; l < m; ++l) {
        ab[i][j] += a[i][l] * b[l][j];
      }
    }
  }
  for (auto a : ab) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << "\n";
  }

  return 0;
}
