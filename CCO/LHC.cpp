// CCO '13 Day 1 Problem 3 - LHC
// https://dmoj.ca/problem/cco13p3

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 400001;
int n,x,y;
long long dp[maxn],cnt,best,node[maxn];
bool flag[maxn];
vector<int> graph[maxn];
void dfs(int u)
{
    flag[u] = true;
    for(int i = 0;i<graph[u].size();i++)
    {
        int v = graph[u][i];
        if (!flag[v])
        {
            dfs(v);
            long long temp = dp[v] + 1;
            if (temp+dp[u]>best)
            {
                best = temp+dp[u];
                cnt = node[v]*node[u];
            }
            else if (temp+dp[u]==best)
            {
                cnt+= node[v]*node[u];
            }
            if(temp>dp[u])
            {
                dp[u] = temp;
                node[u] = node[v];
            }
            else if(temp==dp[u])
            {
                node[u]+=node[v];
            }
        }
    }
}
int main()
{

    scanf("%d",&n);
    for(int i = 0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1;i<=n;i++)
        node[i] = 1;
    dfs(1);
    printf("%lld %lld\n",best+1,cnt);
}
