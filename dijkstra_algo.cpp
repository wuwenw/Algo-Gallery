#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
  // Write your code here;
  vector<int> minDistance(edges.size(), -1);
  // distance, edge index
  auto comp = [](vector<int> &a, vector<int> &b) {
    return a[0] > b[0];
  };
  priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
  minDistance[start] = 0;
  pq.push({0, start});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    int edgeDistance = cur[0];
    int edgeLabel = cur[1];
    if (minDistance[edgeLabel] != -1 && edgeDistance > minDistance[edgeLabel]) {
      continue;
    }
    for (auto &it : edges[edgeLabel]) {
      int nextDistance = it[1];
      int nextLabel = it[0];
      if (minDistance[nextLabel] == -1 || minDistance[nextLabel] > minDistance[edgeLabel] + nextDistance) {
        minDistance[nextLabel] = minDistance[edgeLabel] + nextDistance;
        pq.push({nextDistance, nextLabel});
      }
    }
    
  }
  return minDistance; 
}

