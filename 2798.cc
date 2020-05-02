#include <iostream>
#include <vector>
//#include <algorithm>
//#include <string>
//#include <utility>

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

  int n, m;
  cin >> n >> m;
  vector<int> cards(n);
  for (int i = 0; i < n; i++)
  {
    cin >> cards[i];
  }
  int max_sum = 0;
  int sum = 0;
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        sum = cards[i] + cards[j] + cards[k];
        if (sum <= m && sum > max_sum)
        {
          max_sum = sum;
        }
      }
    }
  }
  cout << max_sum;

  return 0;
}
