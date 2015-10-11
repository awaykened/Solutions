// CCO '07 Day 2 Problem 3 - Road Construction
// http://wcipeg.com/problem/ccc07s2p6

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1001;
int n,m,a,b,low[maxn], dfn[maxn],id[maxn],idx = 1,cnt,ans,sol;
vector<int> adj[maxn],graph[maxn];
vector<int> st;
vector<vector<int> > comps;
bool flag[maxn];
void tarjan(int u, int par) {
      flag[u] = 1;
      low[u] = dfn[u] = cnt++;
      int children = 0;
      st.push_back(u);
      for (int dest: adj[u]) {
            if (dest == par) continue;
            if (flag[dest]) {
                  low[u] = min(low[u],dfn[dest]);
            } else {
                  tarjan(dest,u);
                  low[u] = min(low[u],low[dest]);
                  children ++;
            }
      }
      if (low[u] == dfn[u]) {
            ans ++;
            vector<int> comp;
            while (1) {
                  int x = st.back();
                  comp.push_back(x);
                  id[x] = ans;
                  st.pop_back();
                  if (x == u) break;
            }
            comps.push_back(comp);
      }
}

void rebuild() {
      for (int i = 1;i<=n;i++) {
            for (int dest: adj[i]) {
                  if (id[i] != id[dest])
                        graph[id[i]].push_back(id[dest]);
            }
      }
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 0;i<m;i++) {
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
      tarjan(1,-1);
      rebuild();
      for (int i = 1;i<=ans;i++) {
            if (graph[i].size()==1)
                  sol++;
      }
      cout << (sol+1)/2 << endl;
}
