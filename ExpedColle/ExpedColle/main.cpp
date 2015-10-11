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
const int MAXN =  2001;

int N, R, E;
long long C1, CA, CB, CM, ans;
long long V1, VA, VB, VM;
long long dp[MAXN];
vector<long long> costs[MAXN];
// E, C1, V1, CA, CB, CM, VA, VB, VM

int main() { io
      cin >> N >> R;
      For(i, 1, N) {
            cin >> E >> C1 >> V1 >> CA >> CB >> CM >> VA >> VB >> VM;
            if (C1 <= R)
                  costs[C1].push_back(V1);
            For(j, 2, E) {
                  C1 = (C1 * CA + CB) % CM;
                  V1 = (V1 * VA + VB) % VM;
                  if (C1 > R) continue;
                  costs[C1].push_back(V1);
            }
      }
      For(i, 1, R) {
            sort(costs[i].begin(), costs[i].end());
            reverse(costs[i].begin(), costs[i].end());
      }
      
      For(i, 1, R) { // cost
            int bound = min( (int) (costs[i].size() - 1), 2000 / i + 1);
            For(item, 0, bound) {
                  Rev(j, R, i) {
                        dp[j] = max(dp[j], dp[j - i] + costs[i][item]);
                  }
            }
      }
      ans = dp[R];
      for (int i = 0;i<costs[0].size();i++) {
            ans += costs[0][i];
      }
      cout << ans << endl;
}