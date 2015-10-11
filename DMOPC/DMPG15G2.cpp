// DMPG '15 G2 - 1-String B2-VPG Representation of Planar Graphs
// https://dmoj.ca/problem/dmpg15g2
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
const int MAXN =  5001;

int N, M, a, b ;
struct point {
      int x, y;
}P[MAXN];

struct edge {
      point u, v;
};
vector<edge> E;
vector<int> graph[MAXN];

long long cross(point a1, point a2, point a3)
{
      return (long long)(a1.x-a3.x)*(long long)(a2.y-a3.y)-(long long)(a1.y-a3.y)*(long long)(a2.x-a3.x);
}

bool Intersect(point a1, point a2, point b1, point b2)
{
      int cnt = 0;
      if (a1.x == b1.x && a1.y == b1.y) cnt ++;
      if (a1.x == b2.x && a1.y == b2.y) cnt ++;
      if (a2.x == b1.x && a2.y == b1.y) cnt ++;
      if (a2.x == b2.x && a2.y == b2.y) cnt ++;
      if (cnt == 1) return false;
      else if (cnt == 2) return true;
      if(min(a1.x, a2.x)<=max(b1.x, b2.x)&&
         min(a1.y, a2.y)<=max(b1.y, b2.y)&&
         min(b1.x, b2.x)<=max(a1.x, a2.x)&&
         min(b1.y, b2.y)<=max(a1.y, a2.y)&&
         (long long) cross(a1,a2,b1)*cross(a1,a2,b2)<=0 &&
         (long long) cross(b1,b2,a1)*cross(b1,b2,a2)<=0)
            return true;
      return false;
}


bool check (point A, point B) {
      for (edge e: E) {
            point u = e.u, v = e.v;
            if (Intersect(A, B, u, v))
                  return 0;
      }
      return 1;
}

bool used[MAXN], connected[MAXN][MAXN];
int curr[5], ans;
void solve(int size) {
      ans = max(ans, size);
      if (size == 4) return;
      For(i, 1, N) {
            bool bad = 0;
            if (used[i]) continue;
            For(j, 1, 4) {
                  if (curr[j] > 0 && !connected[curr[j]][i]) {
                        bad = 1; break;
                  }
            }
            if (bad) continue;
            used[i] = 1;
            curr[size + 1] = i;
            solve(size + 1);
            curr[size + 1] = 0;
            used[i] = 0;
      }
}
int main() { io
      cin >> N >> M ;
      For(i, 1, N) {
            cin >> P[i].x >> P[i].y;
      }
      For(i, 1, M) {
            cin >> a >> b;
            if (check(P[a], P[b])) {
                  E.push_back({P[a],P[b]});
                  graph[a].push_back(b);
                  graph[b].push_back(a);
                  connected[a][b] = connected[b][a] = 1;
            }
      }
      solve(0);
      cout << ans << endl;
      
} 
