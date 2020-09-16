#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int v, e, k;
vector<vector<pair<int, int>>> vertices;
vector<int> weights;

void Daikstra() {
  priority_queue<pair<int, int>> pq;
  pq.push({0, k});
  weights[k] = 0;
  while (!pq.empty()) {
    int weight = -pq.top().first, vertex = pq.top().second;
    pq.pop();
    for (int i = 0; i < (int)vertices[vertex].size(); ++i) {
      int next_vertex = vertices[vertex][i].first;
      int next_weight = vertices[vertex][i].second;
      if (weights[next_vertex] > weight + next_weight) {
        weights[next_vertex] = weight + next_weight;
        pq.push({-weights[next_vertex], next_vertex});
      }
    }
  }
}

int main() {
  vertices.clear();
  weights.clear();
  cin >> v >> e >> k;
  vertices.resize(v + 1);
  weights.resize(v + 1, INT_MAX);
  for (int i = 0; i < e; ++i) {
    int f, t, w;
    cin >> f >> t >> w;
    vertices[f].push_back({t, w});
  }
  Daikstra();
  for (int i = 1; i <= v; ++i) {
    if (weights[i] == INT_MAX) cout << "INF \n";
    else cout << weights[i] << '\n';
  }

  return 0;
}
