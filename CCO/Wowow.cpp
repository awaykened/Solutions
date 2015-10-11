// CCO '10 Day 1 Problem 3 - Wowow
// http://wcipeg.com/problem/ccc10s2p3

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
const int maxn = 1000005;
int n,a,b;
unordered_map<int,int> conv,back,ord,ordb;
vector<int> tosort;
vector<pair<char,int> > seq;
int tree[maxn],high,low,mid,v1,v2;
char op;

int main()
{
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        scanf(" %c",&op);
        if (op == 'N')
        {
            scanf("%d%d",&a,&b);
            seq.push_back(make_pair('A',b));
            conv[b] = a; back[a] = b;
            tosort.push_back(b);
        }
        else if (op == 'M')
        {
            scanf("%d%d",&a,&b);
            seq.push_back(make_pair('D',back[a]));
            seq.push_back(make_pair('A',b));
            conv[b] = a; back[a] = b;
            tosort.push_back(b);
        }
        else
        {
            scanf("%d",&a);
            seq.push_back(make_pair('Q',a));
        }
    }
    
    sort(tosort.begin(),tosort.end());
    reverse(tosort.begin(),tosort.end());
    int len = tosort.size();
    
    for (int i = 0;i<len;i++){
        ord[tosort[i]] = i+1;
        ordb[i+1] = tosort[i];
    }
    
    for (int i = 0;i<seq.size();i++)
    {
        if (seq[i].first == 'A')
            for (int j = ord[seq[i].second];j<=maxn;j+=j&-j)
                tree[j] += 1;
        else if (seq[i].first == 'D')
            for (int j = ord[seq[i].second];j<=maxn;j+=j&-j)
                tree[j] -=1;
        else
        {
            int ans = 0, count = 0, value = seq[i].second;
            for (int i = 20; i>=0;i--)
            {
                ans += (1<<i);
                if (ans>maxn || count + tree[ans] >= value) ans -= (1<<i);
                else count+=tree[ans];
            }
            printf("%d\n",conv[ordb[ans+1]]);
        }
    }
}
