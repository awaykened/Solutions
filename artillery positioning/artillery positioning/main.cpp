#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
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
#define Rev(a,b,c) for(int a = b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define io cin.sync_with_stdio(0); cin.tie(0);
#define MTRAND mt19937 gen(4)
#define RNG(l,h) gen() % (h - l + 1) + l

using namespace std;

const int MAXR = 101, MAXC = 11;

int R, C, dp[MAXR][61][61];
char grid[MAXR][MAXC];
vector<int> comb[MAXR];

int solve(int row, int p1, int p2) {
      if (row == R + 1) return 0 ;
      if (dp[row][p1][p2] != -1)
            return dp[row][p1][p2];
      int ret = 0;
      for (int index = 0; index < comb[row].size(); index ++) {
            int mask = comb[row][index];
            if ((row > 1) && (mask & comb[row - 1][p1])) continue;
            if ((row > 2) && ((mask & comb[row - 1][p1]) || (mask & comb[row - 2][p2] || (comb[row - 1][p1] & comb[row - 2][p2])))) continue;
            ret = max(ret, solve(row + 1, index, p1) + __builtin_popcount(mask));
      }
      return dp[row][p1][p2] = ret;
}
int main() { io
      cin >> R >> C;
      For(i, 1, R) For(j, 1, C) {
            cin >> grid[i][j];
      }
      For(i, 1, R) {
            comb[i].push_back(0);
            For(first, 1, C) {
                  if (grid[i][first] != 'P') continue;
                  comb[i].push_back( (1<<first) );
                  For(second, first + 3, C) {
                        if (grid[i][second] != 'P') continue;
                        comb[i].push_back( (1<<first) + (1<<second) );
                        For(third, second + 3, C) {
                              if (grid[i][third] != 'P') continue;
                              comb[i].push_back( (1<<first) + (1<<second) + (1<<third) );
                              For(fourth, third + 3, C) {
                                    if (grid[i][fourth] != 'P') continue;
                                    comb[i].push_back( (1<<first) + (1<<second) + (1<<third) + (1<<fourth) );

                              }
                        }
                  }
            }
      }
      memset(dp, -1, sizeof dp);
      cout << solve(1, 0, 0) << endl;
}
