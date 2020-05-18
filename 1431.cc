#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
  if (a.size() == b.size()) {
    int a_sum = 0, b_sum = 0;
    for (auto c : a) {
      if (isdigit(c))
        a_sum += c - '0';
    }
    for (auto c : b) {
      if (isdigit(c))
        b_sum += c - '0';
    }
    if (a_sum != b_sum)
      return a_sum < b_sum;
    return a < b;
  }
  return a.size() < b.size();
}

int main() {
  int n;
  cin >> n;
  vector<string> vec(n);
  for (int i = 0; i < n; ++i)
    cin >> vec[i];
  sort(vec.begin(), vec.end(), compare);
  for (auto a : vec)
    cout << a << "\n";

  return 0;
}
