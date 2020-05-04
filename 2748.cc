#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> memo(n + 1);
  memo[0] = 0;
  memo[1] = 1;
  for (int i = 2; i <= n; i++)
    memo[i] = memo[i - 1] + memo[i - 2];
  cout << memo[n];

  return 0;
}
