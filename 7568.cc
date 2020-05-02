#include <iostream>
#include <vector>
#include <utility>
//#include <algorithm>
//#include <string>
//#include <cmath>
//#include <climits>

using namespace std;
//using ll = long long;

int main()
{
#define DEBUG
#ifndef DEBUG
#define DEBUG
  FILE* stream;
  freopen_s(&stream, "input.txt", "r", stdin);
  freopen_s(&stream, "output.txt", "w", stdout);
#endif // DEBUG

//#define FASTIO
#ifndef FASTIO
#define FASTIO
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif // FASTIO

  int n;
  cin >> n;
  vector<pair<int, int>> bodies(n);
  vector<int> rank(n, 1);
  for (int i = 0; i < n; i++)
  {
    cin >> bodies[i].first >> bodies[i].second;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (bodies[i].first < bodies[j].first && bodies[i].second < bodies[j].second)
      {
        rank[i]++;
      }
    }
  }
  for (auto a : rank)
  {
    cout << a << " ";
  }

  return 0;
}
