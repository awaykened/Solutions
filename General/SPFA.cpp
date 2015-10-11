#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 100001, inf = 1<<30;
int N, M, S, T, a, b, c, dp[MAXN];
bool inqueue[MAXN];
vector<pair<int, int> > graph[MAXN]; // adjacency list representation

int spfa(int source, int sink) {
      queue <int> q;
      memset(inqueue, 0, sizeof inqueue);
      fill(dp + 1, dp + N + 1, inf);
      dp[source] = 0;
      q.push(source);
      while (!q.empty()) {
            int u = q.front(); q.pop();
            inqueue[u] = 0;
            for (auto p: graph[u]) {
                  int dest = p.first, cost = p.second;
                  if (dp[dest] > dp[u] + cost) {
                        dp[dest] = dp[u] + cost;
                        if (!inqueue[dest]) {
                              q.push(dest);
                              inqueue[dest] = 1;
                        }
                  }
            }
      }
      return dp[sink];
}
int main() {
      scanf("%d %d", &N, &M); // number of nodes and edges
      for (int i = 1; i <= M; i++) {
            scanf("%d %d %d", &a, &b, &c); // there is an edge from a -> b with cost c
            graph[a].push_back(make_pair(b, c)); 
      }
      scanf("%d %d", &S, &T); // source and sink
      printf("%d \n", spfa(S, T));
}
