// CCO '09 Day 2 Problem 2 - Parade
// http://wcipeg.com/problem/ccc09s2p5

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define m(a,b) (a+b)/2
#define lc(a) a<<1
#define rc(a) a<<1|1
using namespace std;

const int maxn = 100001;
int n,q,seq[maxn][16],a,b,c,d,grid[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
void rot(int sy,int sx,int w,int pos)
{
    int grid[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int temp[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for(int i = sx+1;i<sx+w;i++)
        temp[sy*4+i] = grid[sy*4+i-1];
    for(int i = sx;i<sx+w-1;i++)
        temp[(sy+w-1)*4+i] = grid[(sy+w-1)*4+i+1];
    for(int j = sy;j<sy+w-1;j++)
        temp[j*4+sx] = grid[(j+1)*4+sx];
    for(int j = sy+1;j<sy+w;j++)
        temp[j*4+sx+w-1] = grid[(j-1)*4+sx+w-1];
    for(int i = 0;i<16;i++)
        seq[pos][i] = temp[i];
}
struct node
{
    int l,r,perm[16];
    
}tree[3*maxn];

void push_up(int index)
{
    for(int i = 0;i<16;i++)
        tree[index].perm[i] = tree[lc(index)].perm[tree[rc(index)].perm[i]];
}

void build(int l,int r,int index)
{
    tree[index].l = l;
    tree[index].r = r;
    if (tree[index].l==tree[index].r)
    {
        for(int i = 0;i<16;i++)
            tree[index].perm[i] = seq[l][i];
        return;
    }
    int mid = m(l,r);
    build(l,mid,lc(index));
    build(mid+1,r,rc(index));
    push_up(index);
}

void update(int pos,int index)
{
    if (tree[index].l==tree[index].r)
    {
        for(int i = 0;i<16;i++)
            tree[index].perm[i] = seq[tree[index].l][i];
        return;
    }
    int mid = m(tree[index].l,tree[index].r);
    if (pos<=mid) update(pos,lc(index));
    else update(pos,rc(index));
    push_up(index);
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        rot(a-1,b-1,c,i);
    }
    build(1,n,1);
    for(int i = 0;i<q;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        rot(b-1,c-1,d,a);
        update(a,1);
        for(int x = 0;x<4;x++)
        {
            for(int y = 0;y<4;y++)
            {
                printf("%d ",grid[tree[1].perm[4*x+y]]);
            }
            printf("\n");
        }
        cout<<endl;
    }
}
