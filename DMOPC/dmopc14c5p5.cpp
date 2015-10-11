// DMOPC '14 Contest 6 P5 - Attack on Anti-Spiral
// https://dmoj.ca/problem/dmopc14c5p5

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100001;
int n,m,a,b,c,num[maxn],low[maxn], idx = 1;
long long dp[maxn],dpcyc[maxn];
vector <pair <int,int> > adj[maxn],st,art[maxn];
vector <vector<pair<int,int > > > cyc[maxn];
bool bridge[maxn],flag[maxn];

void dfs(int u, int par, int d) { // current node, parent node, cost from prev to this node
    num[u] = low[u] = idx;
    st.push_back(make_pair(u,d));
    idx ++;
    for (int i = 0;i<adj[u].size();i++) {
        int dest = adj[u][i].first;
        int cost = adj[u][i].second;
        if (dest != par) {
            if (!num[dest]) {
                dfs(dest,u,cost);
                if (low[dest] > num[u]) {        // num[u] < low[v] means v is on a bridge of u
                    art[u].push_back(st.back()); // num[u] <= low[v] means v is articulation point
                    st.pop_back();
                    bridge[dest] = true;
                } else if (low[dest] < num[u]) {
                    low[u]= low[dest];
                } else {                        // num[u] == low[v] means v is on loop of u
                    vector <pair<int,int> > hold;
                    for (int j = 0;j<adj[u].size();j++){
                        int destj = adj[u][j].first;
                        int costj = adj[u][j].second;
                        if (destj == st.back().first){
                            hold.push_back(make_pair(u,costj));
                            break;
                        }
                    }
                    while (st.back().first!=dest) {
                        hold.push_back(st.back());
                        st.pop_back();
                    }
                    hold.push_back(st.back());
                    st.pop_back();
                    cyc[u].push_back(hold);     // hold is a loop
                }
            }
            else
                low[u] = min(low[u],num[dest]);
        }
    }
}

void dfs2(int u, bool bridged) {
    flag[u] = true;
    bridge[u] = bridged;
    for (int i = 0;i<cyc[u].size();i++) {
        long long tot = 0;
        for (int j = 0;j<cyc[u][i].size();j++) {         // calculate tot in cycle
            int dest = cyc[u][i][j].first;
            int cost = cyc[u][i][j].second;
            tot += cost;
        }
        long long path = 0;
        for (int j = 1;j<cyc[u][i].size();j++) {
            int dest = cyc[u][i][j].first;
            int cost = cyc[u][i][j-1].second;
            path += cost;
            dp[dest] = dp[u] + min(path, tot-path);   // paths from both sides of loop
            dpcyc[dest] = dpcyc[u] + tot;                  // sum of cycles....
            if (!flag[dest])
                dfs2(dest,bridged);
        }
    }
    // loop through articulation points, went through bridge
    for (int i = 0;i<art[u].size();i++) {
        int dest = art[u][i].first;
        int cost = art[u][i].second;
        dp[dest] = dp[u] + cost;
        if (!flag[dest])
            dfs2(dest,1);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 0;i<m;i++) {
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    dfs(1,-1,0);
    dfs2(1,false);
    for (int i = 2;i<=n;i++) {
        if (bridge[i])
            printf("%d %lld\n",1,dp[i]);
        else
            printf("%d %lld\n",2,dpcyc[i]);
    }
}
