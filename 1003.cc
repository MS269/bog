#include <iostream>
#include <vector>

using namespace std;

const int kMax = 40;

int main() {
  int t;
  cin >> t;
  vector<int> memo(kMax + 1);
  memo[0] = 0;
  memo[1] = 1;
  for (int i = 2; i <= kMax; i++)
    memo[i] = memo[i - 1] + memo[i - 2];
  while (t--) {
    int n;
    cin >> n;
    if (n == 0)
      cout << 1 << " " << 0 << "\n";
    else
      cout << memo[n - 1] << " " << memo[n] << "\n";
  }

  return 0;
}
