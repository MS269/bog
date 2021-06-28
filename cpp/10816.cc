#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
  int n, m, temp;
  cin >> n;
  vector<int> cards(n);
  for (int i = 0; i < n; ++i) { cin >> cards[i]; }
  sort(cards.begin(), cards.end());
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> temp;
    cout << upper_bound(cards.begin(), cards.end(), temp) 
      - lower_bound(cards.begin(), cards.end(), temp) << "\n";
  }

  return 0;
}
