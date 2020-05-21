#include <iostream>
#include <map>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<string, int> clothes;
    for (int i = 0; i < n; ++i) {
      string name, type;
      cin >> name >> type;
      if (clothes.find(type) == clothes.end()) { clothes.insert({type, 1}); }
      else { ++clothes[type]; }
    }
    int ans = 1;
    for (auto a : clothes) { ans *= (a.second + 1); }
    ans -= 1;
    cout << ans << "\n";
  }

  return 0;
}
