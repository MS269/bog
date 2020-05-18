#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
  if (a.size() == b.size())
    return a < b;
  return a.size() < b.size();
}

int main() {
  int n;
  cin >> n;
  vector<string> vec(n);
  for (int i = 0; i < n; ++i)
    cin >> vec[i];
  sort(vec.begin(), vec.end(), compare);
  cout << vec[0] << "\n";
  for (int i = 1; i < n; ++i) {
    if (vec[i - 1] != vec[i])
      cout << vec[i] << "\n";
  }

  return 0;
}
