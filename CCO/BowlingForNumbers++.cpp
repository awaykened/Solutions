// CCO '07 Day 2 Problem 3 - Bowling for Numbers ++
// http://wcipeg.com/problem/ccc07s2p3

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 20010;
int t,n,k,w, dp[510][maxn], pins[maxn], prefix[maxn],pos;


int solve(int ball, int pos) {
      if (ball <= 0 || pos < 0)
            return 0;
      if (dp[ball][pos] != -1)
            return dp[ball][pos];
      int ret = 0,first = max(0,pos - w),val = prefix[pos] - prefix[first]; // (first + 1 --> pos)
      ret = max(solve(ball,pos-1),solve(ball-1,first) + val);
      if (ball >= 2) {
            int sum = 0;
            for (int i = first; i>first-w+1;i--) {
                  if (i < 0) break;
                  sum += pins[i];
                  ret = max(ret,solve(ball-2,i-1) + val + sum);
            }
      }
      return dp[ball][pos] = ret;
}

int main()
{
    //  freopen("bowlingfornumbers++.txt","r",stdin);;
      scanf("%d",&t);
      for (int zz = 0;zz<t;zz++)
      {
            memset(dp,-1,sizeof dp);
            memset(prefix,0,sizeof prefix);
            scanf("%d%d%d",&n,&k,&w);
            for (int i = 1;i<=n;i++) {
                  scanf("%d",&pins[i]);
            }
            
            for (int i = 1;i<=n+w;i++)
            {
                  prefix[i] = prefix[i-1] + pins[i];
            }
            cout << solve(k,n+w) << endl;
      }
}
