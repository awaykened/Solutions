// DMOPC '14 Exam Time P6 - Math Homework
// https://dmoj.ca/problem/dmopc14ce1p6

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
const int MAXN =  3005, mod = (1e9 + 7);

int T, R, C; int dp[MAXN][MAXN];
long long ans;

long long exp(long long N, int e) {
      if (e == 0) return 1;
      if (e == 1) return N;
      if (e & 1) return N * exp((N * N) % mod, (e - 1) / 2) % mod;
      return exp((N * N) % mod, e / 2) % mod;
}

int main() {
      scan(T);
      For(i, 0, MAXN - 1)
            dp[i][0] = 1;
      For(i, 1, MAXN - 1)
            For(j, 1, MAXN - 1) {
                  dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                  dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      }
      
      while (T --) {
            ans = 1;
            scan(R); scan(C);
            long long init = ((exp(2, C) % mod) - 1) % mod;
            ans = exp(init, R) % mod;
            For(i, 1, C) {
                  if (i & 1)
                        ans = (ans - ((exp( (exp(2, C - i) % mod - 1) % mod, R) % mod) * dp[C][i]) % mod) % mod;
                  else ans = (ans + ((exp( (exp(2, C - i) % mod - 1) % mod, R) % mod) * dp[C][i]) % mod) % mod;
                  if (ans < 0) ans += mod;
            }
            printf("%lld\n",ans);
      }
      
}
