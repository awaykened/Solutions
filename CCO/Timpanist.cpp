// CCO '15 Day 2 Problem 2 - Timpanist
// https://dmoj.ca/problem/cco15p5

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
#define inf 1<<30
#define lc(x) x<<1
#define rc(x) x<<1|1
#define m(a,b) (a+b)/2
#define EPS 1e-6
#define PI 3.1415926535897932384
#define For(a,b,c) for(int a = b;a<=c;a++)
#define pb push_back
#define mp make_pair

using namespace std;
const int maxn = 101;
int N,D,T[maxn],P[maxn];
double dp[maxn][13][13][13][13];

double solve4(int t, int a, int b, int c, int d) {
      if (t == N) return inf;
      if (dp[t][a][b][c][d] != -1)
            return dp[t][a][b][c][d];
      double ret = 0;
      For(i,1,12) {
            For(j,i+1,12) {
                  For(k,j+1,12) {
                        For(l,k+1,12) {
                              int cnt = 0;
                              if (D == 4 && i != P[t+1] && j != P[t+1] && k != P[t+1] && l != P[t+1]) continue;
                              if (D == 3 && i != P[t+1] && j != P[t+1] && k != P[t+1]) continue;
                              if (D == 2 && i != P[t+1] && j != P[t+1]) continue;
                              if (D == 1 && i != P[t+1]) continue;
                              if (i != a) cnt ++;
                              if (D > 1 && j != b) cnt ++;
                              if (D > 2 && k != c) cnt ++;
                              if (D > 3 && l != d) cnt ++;
                              ret = max(ret,min((cnt==0)?inf:(double)(T[t+1]-T[t])/cnt,solve4(t+1,i,j,k,l)));
                        }
                  }
            }
      }
      
      return dp[t][a][b][c][d] = ret;
}
double solve3(int t, int a, int b, int c) {
      if (t == N) return inf;
      if (dp[t][a][b][c][1] != -1)
            return dp[t][a][b][c][1];
      double ret = 0;
      For(i,1,12) {
            For(j,i+1,12) {
                  For(k,j+1,12) {
                        int cnt = 0;
                        if (D == 3 && i != P[t+1] && j != P[t+1] && k != P[t+1]) continue;
                        if (D == 2 && i != P[t+1] && j != P[t+1]) continue;
                        if (D == 1 && i != P[t+1]) continue;
                        if (i != a) cnt ++;
                        if (D > 1 && j != b) cnt ++;
                        if (D > 2 && k != c) cnt ++;
                        ret = max(ret,min((cnt==0)?inf:(double)(T[t+1]-T[t])/cnt,solve3(t+1,i,j,k)));
                  }
            }
      }
      return dp[t][a][b][c][1] = ret;
}
double solve2(int t, int a, int b) {
      if (t == N) return inf;
      if (dp[t][a][b][1][1] != -1)
            return dp[t][a][b][1][1];
      double ret = 0;
      For(i,1,12) {
            For(j,i+1,12) {
                  int cnt = 0;
                  if (D == 2 && i != P[t+1] && j != P[t+1]) continue;
                  if (D == 1 && i != P[t+1]) continue;
                  if (i != a) cnt ++;
                  if (D > 1 && j != b) cnt ++;
                  ret = max(ret,min((cnt==0)?inf:(double)(T[t+1]-T[t])/cnt,solve2(t+1,i,j)));

            }
      }
      
      return dp[t][a][b][1][1] = ret;
}

double solve1(int t, int a) {
      if (t == N) return inf;
      if (dp[t][a][1][1][1] != -1)
            return dp[t][a][1][1][1];
      double ret = 0;
      For(i,1,12) {
            int cnt = 0;
            if (D == 1 && i != P[t+1]) continue;
            if (i != a) cnt ++;
            ret = max(ret,min((cnt==0)?inf:(double)(T[t+1]-T[t])/cnt,solve1(t+1,i)));

      }
      return dp[t][a][1][1][1] = ret;
}

int main() {
      //freopen("text.txt","r",stdin);
      scan(N); scan(D);
      For(i,1,N) {
            scan(T[i]); scan(P[i]);
      }
      For(t,1,100) For(i,1,12) For(j,1,12) For(k,1,12) For(l,1,12)
      dp[t][i][j][k][l] = -1;
      double ans = 0.0;
      if (D == 4) {
            For(i,1,12) For(j,i+1,12) For(k,j+1,12) For(l,k+1,12)  {
                  if (D == 4 && i != P[1] && j != P[1] && k != P[1] && l != P[1]) continue;
                  ans = max(ans,solve4(1,i,j,k,l));
            }
      } else if (D == 3) {
            For(i,1,12) For(j,i+1,12) For(k,j+1,12)  {
                  if (D == 3 && i != P[1] && j != P[1] && k != P[1]) continue;
                  ans = max(ans,solve3(1,i,j,k));
            }
      } else if (D == 2) {
            For(i,1,12) For(j,i+1,12) {
                  if (D == 2 && i != P[1] && j != P[1]) continue;
                  ans = max(ans,solve2(1,i,j));
            }
      } else {
            For(i,1,12) {
                  if (D == 1 && i != P[1]) continue;
                  ans = max(ans,solve1(1,i));
            }
      }
      printf("%.2lf",(ans==inf)?0.00:ans);
}
