#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> bodies(n);
  vector<int> rank(n, 1);
  for (int i = 0; i < n; i++)
    cin >> bodies[i].first >> bodies[i].second;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (bodies[i].first < bodies[j].first && bodies[i].second < bodies[j].second)
        rank[i]++;
    }
  }
  for (auto a : rank)
    cout << a << " ";

  return 0;
}
