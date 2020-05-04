#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> vec;
int subset_cnt = 0;

void GetSubsets(int cnt, int sum) {
  if (cnt == n)
    return;
  if (sum + vec[cnt] == s)
    subset_cnt++;
  GetSubsets(cnt + 1, sum);
  GetSubsets(cnt + 1, sum + vec[cnt]);
}

int main() {
  cin >> n >> s;
  vec.resize(n);
  for (int i = 0; i < n; i++)
    cin >> vec[i];
  GetSubsets(0, 0);
  cout << subset_cnt;

  return 0;
}
