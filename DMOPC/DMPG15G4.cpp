// DMPG '15 G4 - Spacetime Convergence Cannons
// https://dmoj.ca/problem/dmpg15g4

#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <assert.h>
#include <unordered_map>
#include <cmath>
#include <random>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define inf 1<<30
#define lc(x) x<<1
#define rc(x) x<<1|1
#define m(a,b) (a+b)/2
#define EPS 1e-9
#define PI 3.1415926535897932384
#define For(a,b,c) for(int a = b;a<=c;a++)
#define Rev(a,b,c) for(int a = b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define io cin.sync_with_stdio(0); cin.tie(0);
#define MTRAND mt19937 gen(4)
#define RNG(l,h) gen() % (h - l + 1) + l
using namespace std;
const int MAXN =  200005;

int x[MAXN], y[MAXN], N,X, id = 0;
pair<double, double> cannons[MAXN];
pair<int, int> C[MAXN];
double tosort[2*MAXN];
int cmpid, bit[2*MAXN];
unsigned long long ans;
// tan(theta1) = y/x
// tan(theta2) = y/(X-x)

void update(int x) {
      for(; x < 2*MAXN; x += x & -x) {
            bit[x] ++;
      }
}

int query(int x) {
      int ret = 0;
      for(; x > 0; x-= x & -x) {
            ret += bit[x];
      }
      return ret;
}

int main() {
      scan(N); scan(X);
      For(i,1,N) {
            scan(x[i]); scan(y[i]);
            double theta1 = atan((double)y[i]/(double)x[i]);
            double theta2 = atan((double)y[i]/((double)X-(double)x[i]));
            cannons[i] = make_pair(theta1,theta2);
            tosort[++id] = theta1; tosort[++id] = theta2;
      }
      sort(tosort+1,tosort+1+id);
      
      For(i,1,N) {
            C[i].first = id - (lower_bound(tosort+1,tosort+1+id,cannons[i].first) - tosort) + 3;
            C[i].second = id - (lower_bound(tosort+1,tosort+1+id,cannons[i].second) - tosort) + 3;
      }
      
      sort(C + 1, C + 1 + N);
      
      For(i,1,N) {
            int v = query(C[i].second);
            ans += (long long) v*v;
            update(C[i].second);
      }
      cout << ans << endl;
}
