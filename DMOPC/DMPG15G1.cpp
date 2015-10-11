// DMPG '15 G1 - Marcia and Maze
// https://dmoj.ca/problem/dmpg15g1

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
const int MAXN =  501;
char grid[MAXN][MAXN];
int U[MAXN][MAXN], D[MAXN][MAXN], L[MAXN][MAXN], R[MAXN][MAXN];
int N, ans;

int main() { io
      cin >> N ;
      For(i, 1, N) For(j, 1, N)
            cin >> grid[i][j];
      
      For(i, 1, N) {
            For(j, 1, N) {
                  if (grid[i][j] == '#')
                        L[i][j] = 0;
                  else L[i][j] = L[i][j - 1] + 1;
            }
      }
      
      For(i, 1, N) {
            Rev(j, N, 1) {
                  if (grid[i][j] == '#')
                        R[i][j] = 0;
                  else R[i][j] = R[i][j + 1] + 1;
            }
      }
      
      For(j, 1, N) {
            For(i, 1, N) {
                  if (grid[i][j] == '#')
                        U[i][j] = 0;
                  else U[i][j] = U[i - 1][j] + 1;
            }
      }
      
      For(j, 1, N) {
            Rev(i, N, 1) {
                  if (grid[i][j] == '#')
                        D[i][j] = 0;
                  else D[i][j] = D[i + 1][j] + 1;
            }
      }
      Rev(size, N, 1) {
            For(i, 1, N - size + 1) {
                  For(j, 1, N - size + 1) {
                        if (D[i][j] < size) continue;
                        if (R[i + size - 1][j] < size) continue;
                        if (U[i + size - 1][j + size - 1] < size) continue;
                        if (L[i][j + size - 1] < size) continue;
                        ans = size;
                        goto done;
                  }
            }
      }
done: printf("%d\n", ans - 1);
}
