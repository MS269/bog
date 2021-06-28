#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int kRange = 10000;

int main() {
  int n;
  scanf("%d", &n);
  int temp;
  vector<int> cnt(kRange + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    ++cnt[temp];
  }
  for (int i = 1; i <= kRange; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      printf("%d\n", i);
    }
  }

  return 0;
}
