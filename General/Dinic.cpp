#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <random>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define inf 99999999
#define lc(x) x<<1
#define rc(x) x<<1|1
#define m(a,b) (a+b)/2
#define EPS 1e-6
#define PI 3.1415926535897932384
#define For(a,b,c) for(int a = b;a<=c;a++)
#define Rev(a,b,c) for(int a = b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define io cin.sync_with_stdio(0); cin.tie(0);
#define MTRAND mt19937 gen(4)
#define RNG(l,h) gen() % (h - l + 1) + l
using namespace std;
const int MAXN =  50001;

struct Edge {
      int from, to, flow;
};

vector<Edge> E;
vector<int> G[MAXN];
int dp[MAXN], cur[MAXN], S = 0, T;
int N, M, lava;

void add(int from, int to, int flow) {
      E.push_back({from, to, flow});
      E.push_back({to, from, 0});
      int m = (int) E.size();
      G[from].push_back(m - 2);
      G[to].push_back(m - 1);
}

bool bfs() {
      queue <int> q;
      memset(dp, -1, sizeof dp);
      dp[S] = 0;
      q.push(S);
      while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i: G[u]) {
                  Edge& e = E[i];
                  if (e.flow && dp[e.to] == -1) {
                        dp[e.to] = dp[u] + 1;
                        if (e.to == T)
                              return 1;
                        q.push(e.to);
                  }
            }
      }
      return 0;
}

int dfs(int u, int bound) {
      if (u == T || !bound)
            return bound;
      int flow = 0, f;
      for (int &i = cur[u]; i < G[u].size(); i++) {
            Edge &e = E[G[u][i]];
            if (e.flow && dp[u] + 1 == dp[e.to] && (f = dfs(e.to, min(bound, e.flow)))) {
                  e.flow -= f;
                  E[G[u][i] ^ 1].flow += f;
                  flow += f;
                  bound -= f;
                  if (bound == 0)
                        break;
            }
      }
      return flow;
}
int maxflow() {
      int flow = 0;
      while (bfs()) {
            memset(cur, 0, sizeof cur);
            flow += dfs(S, inf);
      }
      return flow;
}


//Using revenge of the digger as template
int main() { io
      cin >> N >> M ;
      For(i, 0, N - 1) {
            cin >> lava;
            if (!lava) T = i * 2;
            add(i * 2, i * 2 + 1, lava);
      }
      For(i, 1, M) {
            int a, b;
            cin >> a >> b;
            a --; b --;
            add(a * 2 + 1, b * 2, inf);
      }
      cout << maxflow() << endl;
}
