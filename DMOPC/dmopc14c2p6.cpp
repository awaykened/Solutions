// DMOPC '14 Contest 2 P6 - Selective Cutting
// https://dmoj.ca/problem/dmopc14c2p6

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct calvin
{
    int l,h,k,index;
};
int n,q,a,b,x,bit[100001],ans[100001];
pair<int,int>trees[100001];
calvin qs[100001];

void update(int pos,int x)
{
    for(int i=pos;i<=n;i+=(i&-i))
        bit[i]+=x;
}
int query(int pos)
{
    int ans=0;
    for(int i=pos;i>0;i-=(i&-i))
        ans+=bit[i];
    return ans;
}
bool cmp(calvin a,calvin b)
{
    return a.k<b.k;
}
int main()
{
    //freopen("DATA.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        trees[i]=make_pair(-x,i);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&a,&b,&x);
        qs[i]=calvin{++a,++b,-x,i};
    }
    sort(trees+1,trees+n+1);
    sort(qs+1,qs+q+1,cmp);
    for(int j=1,i=1;j<=q;j++)
    {
        while(i<=n&&trees[i].first<=qs[j].k)
            update(trees[i].second,trees[i].first),i++;
        ans[qs[j].index]=query(qs[j].h)-query(qs[j].l-1);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",-ans[i]);
    return 0;
}
