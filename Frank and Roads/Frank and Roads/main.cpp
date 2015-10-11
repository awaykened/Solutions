#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <random>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define inf 1<<30
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
const int MAXN =  2005;

int T, N, M, G, gg, ans;
vector<int> g;
long long dp[MAXN]; bool flag[MAXN];
vector<pair<int, long long> > graph[MAXN];
int main() { io
      cin >> T >> N >> M >> G;
      For(i, 1, G) {
            cin >> gg;
            if (gg == 0 || gg > N ) continue;
            g.push_back(gg);
      }
      For(i, 1, M) {
            int a, b, c;
            cin >> a >> b >> c;
            if (c > T) continue;
            graph[a].push_back(make_pair(b, c));
      }
      
      For(i, 0, N)
            dp[i] = (long long) inf * inf;
      queue <int> q;
      q.push(0); dp[0] = 0;
      while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (pair<int,int> p: graph[u]) {
                  int v = p.first, cost = p.second;
                  if (dp[v] > dp[u] + cost) {
                        dp[v] = dp[u] + cost;
                        q.push(v);
                  }
            }
      }
      
      for (int each: g)
            if (dp[each] < T - 1)
                  ans ++;
      
      cout << ans << endl;
}