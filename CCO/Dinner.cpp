// CCO '09 Day 1 Problem 2 - Dinner
// http://wcipeg.com/problem/ccc09s2p2

#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n,k,group,cnt[2],dp[2][102][102];
bool seq[102];
char ch;

int main() {
      scanf("%d%d",&n,&k);
      for (int i = 1;i<=n;i++) {
            scanf(" %c",&ch);
            seq[i] = (ch=='H');
            if (i == 1 || seq[i] != seq[i-1])
                  group ++;
            for (int j = 1;j<=n+1;j++)
                  dp[0][i][j] = dp[1][i][j] = -1;
            dp[seq[i]][i][i+1] = 1;
      }

      for (int len = 2;len<=n+1;len++) {
            for (int i = 1;i+len<=n+1;i++) {
                  int j = i+len;
                  for (int type = 0;type<2;type++) {
                        for (int mid = i;mid <= j;mid++) {
                              int a = dp[type][i][mid];
                              int b = dp[type][mid][j];
                              if (a != -1 && b != -1)
                                    dp[type][i][j] = max(dp[type][i][j],a+b);
                        }
                        if (dp[type][i][j] >= k)
                              dp[1-type][i][j] = max(dp[1-type][i][j],0);
                  }
            }
      }

      if (dp[0][1][n+1] >= k || dp[1][1][n+1] >= k)
            cout << group/2+1 << endl;
      else
            cout << -1 << endl;
      
}
