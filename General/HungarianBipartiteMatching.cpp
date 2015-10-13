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
const int MAXN =  1001;

bool graph[MAXN][MAXN], flag[MAXN];
int A, B, a, b, pre[MAXN];

bool dfs(int u) {
      For(v, 1, B) {
            if (graph[u][v] && !flag[v]) {
                  flag[v] = 1;
                  if (!pre[v] || dfs(pre[v])) {
                        pre[v] = u;
                        return 1;
                  }
            }
      }
      return 0;
}

int main() {
      cin >> A >> B >> M ;  // number of nodes in first set, second set, number of connections
      For(i, 1, M) {
            cin >> a >> b;
            graph[a][b] = 1;
      }

      For(i, 1, N) {
            memset(flag, 0, sizeof flag);
            if (dfs(i))
                  cnt ++;
      }
      printf("%d\n", cnt); // returns maximum matching
}
