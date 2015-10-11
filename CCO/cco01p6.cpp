// CCO '01 - Election Night
// http://wcipeg.com/problem/ccc01s2p6

#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define inf 1<<18
#define lc(x) x<<1
#define rc(x) x<<1|1
#define m(a,b) (a+b)/2
#define io cin.sync_with_stdio(0); cin.tie(0);
#define EPS 1e-6
#define PI 3.1415926535897932384
#define For(a,b,c) for(int a = b;a<=c;a++)
#define p(n) god.push_back(n);
using namespace std;
const int MAXN = 101;
int N,M,S,s,other[MAXN];
bool vote[MAXN][MAXN]; // vote [i,j] person i votes for j
vector<int> states[MAXN];
queue <int> q;
int graph[2*MAXN+5][2*MAXN+5],dp[2*MAXN+5],par[2*MAXN+5];

// 0 source, N+M+2 sink
int main() {
      io
      while (1) {
            For(i,1,MAXN) states[i].clear();
            memset(vote, 0, sizeof vote);
            memset(graph, -1, sizeof graph);
            cin >> N >> M ;
            if (N == 0 && M == 0) break;
            For(i,1,N) {
                  graph[0][i] = 1;
                  cin >> S;
                  For(j,1,S) {
                        cin >> s;
                        states[i].push_back(s);
                        vote[i][s] = 1;
                        graph[i][s+N] = inf;
                  }
            }
            For(i,1,M) {
                  int cnt = 0, possible=0;
                  bool notwin = 0;
                  memset(other, 0 , sizeof other);
                  For(j,1,N) {
                        if (states[j].size() == 1 && states[j][0] == i)
                              cnt ++;
                        else {
                              for (int k = 0;k<states[j].size();k++)
                                    other[states[j][k]]++;
                        }
                  }
                  For(i,1,M)
                        if (other[i] >= cnt) {
                              notwin= 1;
                              break;
                        }
                  
                  if (!notwin) {
                        cout << "Candidate " << i << " will become president." << endl;
                        continue;
                  }
                  
                  For(j,1,N) {
                        if(vote[j][i]) {
                              possible ++;
                              graph[0][j] = 0;
                        } else graph[0][j] = 1;
                  }
                  For(j,1,M) {
                        graph[N+j][N+M+2] = 0;
                        if (j != i) {
                              graph[N+j][N+M+2] = possible - 1;
                        }
                  }
                  int flow = 0;
                  while (1) {
                        q.push(0);
                        memset(dp,-1,sizeof dp);
                        dp[0] = inf;
                        memset(par,-1,sizeof par);
                        while (!q.empty()) {
                              int u = q.front(); q.pop();
                              for(int v = 0;v<=N+M+2;v++) {
                                    if(graph[u][v] > 0 && dp[v] == -1) {
                                          dp[v] = min(dp[u], graph[u][v]);
                                          q.push(v);
                                          par[v] = u;
                                    }
                              }
                        }
                        if (dp[N+M+2] == -1) break;
                        int current = N+M+2;
                        flow += dp[N+M+2];
                        while (1) {
                              int parent = par[current];
                              if (parent == -1) break;
                              graph[parent][current] -= dp[N+M+2];
                              graph[current][parent] += dp[N+M+2];
                              current = parent;
                        }
                  }
                  if (flow == N - possible) cout << "Candidate " << i << " may become president." << endl;
                  else cout << "Candidate " << i <<  " will not become president." << endl;
            }
      }
}
