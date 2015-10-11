// DMPG '15 G6 - Yōkan
// https://dmoj.ca/problem/dmpg15g6

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
#define io cin.sync_with_stdio(0); cin.tie(0);
#define RNG(a,b) rand()%(b-a+1)+a

using namespace std;
const int MAXN =  200005, K = 35;

int N,Q,M,l,r,flav[MAXN];
vector<int> occur[MAXN];
bool good , hit[MAXN];
int main() {
      srand(6);
      cin >> N >> M ;
      For (i, 1, N) {
            scan(flav[i]);
            occur[flav[i]].push_back(i);
      }
      
      cin >> Q;
      while (Q -- ) {
            scan(l) ; scan(r);
            int len = r - l + 1, num = 0;
            double tar = (double) len / 3;
            memset(hit, 0, sizeof hit);
            For(i, 1, K) {
                  int ele = flav[RNG(l, r)];
                  if (hit[ele]) continue;
                  hit[ele] = 1;
                  int cnt = upper_bound(occur[ele].begin(), occur[ele].end(), r) -
                            lower_bound(occur[ele].begin(), occur[ele].end(), l);
                  if ( (double) cnt >= tar * 2) num += 2;
                  else if ( (double) cnt >= tar) num += 1;
                  if (num >= 2)  {good = 1; break;}
            }
            if (good) puts("YES");
            else puts("NO");
            good = 0;
      }
}
