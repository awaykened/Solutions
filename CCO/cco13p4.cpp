// CCO '13 - A Romantic Movie Outing
// https://dmoj.ca/problem/cco13p4

#include <iostream>
#include <cstdio>
#define dr(r,c) 1800+r-c
#define dc(r,c) r+c+1
using namespace std;
const int inf = 999999999;
int l,t,y,x,bit[3901][3901],ans,r,c,k,first = inf,second = inf;
char op;
bool flag[1801][1001];

void update(int r,int c,int x) {
    for(int i=r;i<3901;i+=i&-i)
        for(int j=c;j<3901;j+=j&-j) {
            bit[i][j]+=x;
        }
}
int query(int r,int c) {
    int ret=0;
    for(int i=r;i>0;i-=i&-i)
        for(int j=c;j>0;j-=j&-j)
            ret+=bit[i][j];
    return ret;
}

int main() {
    scanf("%d%d",&l,&t);
    while (t--) {
        scanf(" %c%d%d",&op,&r,&c);
        if (r > 1800) continue;
        if (op == 'E') {
            flag[r][c] = true;
            update(1800+r-c,r+c+1,1);
        } else if (op == 'L') {
            flag[r][c] = false;
            update(1800+r-c,r+c+1,-1);
        } else {
            if (flag[r][c] || flag[r][c+1]) puts ("No");
            else printf("%d\n",query(1800+r-c,r+c+1) + query(1799+r-c,r+c+2));
        }
    }
    for (int i = l+1;i<=1800;i++)
        for (int j = 1; j<= 1000;j++)
            if (!flag[i][j]) {
                int curr = query(1800+i-j,i+j+1);
                if (curr < second) {
                    second = curr;
                    if (second < first)
                        swap(first,second);
                }
            }
    printf("%d\n",first+second);
}
