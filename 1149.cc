#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> cost(n + 1, vector<int>(3));
  for (int i = 1; i <= n; i++)
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  for (int i = 1; i <= n; i++) {
    cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
    cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
    cost[i][2] += min(cost[i - 1][1], cost[i - 1][0]);
  }
  cout << min(cost[n][0], min(cost[n][1], cost[n][2]));

  return 0;
}
