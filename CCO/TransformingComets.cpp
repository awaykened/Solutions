// CCO '13 Day 2 Problem 2 - Transforming Comets
// https://dmoj.ca/problem/cco13p5

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 500005;
struct point {
    int x,y;
}pointsa[maxn],pointsb[2*maxn];
int t,n,xi,yi,prefix[maxn],len,pos,ans,i,j;
double seqa[maxn],seqb[2*maxn];

double dist(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cross(point a, point b, point c) {
    return (a.x-c.x)*(b.y-c.y) - (a.y-c.y)*(b.x-c.x);
}
double angle(point a, point b, point c) {
    double x1 = (a.x-b.x), x2 = c.x-b.x, y1 = (a.y-b.y), y2 = c.y-b.y;
    return atan2(x1*y2-y1*x2,x1*x2+y1*y2)*(dist(a,b)/dist(b,c));
}
bool double_equals(double a, double b, double epsilon = 1e-7)
{
    return std::abs(a - b) < epsilon;
}
int main() {
    scanf("%d",&t);
    while (t--) {
        ans = -1;
        scanf("%d",&n);
        for (int i = 0;i<=n;i++)
            prefix[i] = 0;
        for (int i = 0;i<n;i++)
            scanf("%d%d",&pointsa[i].x,&pointsa[i].y);
        for (int i = 0;i<n;i++)
            scanf("%d%d",&pointsb[i].x,&pointsb[i].y);
        for (int i = 0;i<n;i++)
            seqa[i] = angle(pointsa[i],pointsa[(i+1)%n],pointsa[(i+2)%n]);
        for (int i = 0;i<n;i++)
            seqb[i] = angle(pointsb[i],pointsb[(i+1)%n],pointsb[(i+2)%n]);
        for (int i = 0;i<n;i++)
            seqb[i+n] = seqb[i];
        prefix[0] = -1;
        
        i = -1 , j = 0;
        while (j<n) {
            if (i == -1 || double_equals(seqa[i],seqa[j])) {
                i++, j++;
                prefix[j] = i;
            } else
                i = prefix[i];
        }
        i = 0, j = 0;
        while (i< 2*n && j<n) {
            if (j == -1 || double_equals(seqa[j],seqb[i])) {
                i++ , j++;
            } else
                j = prefix[j];
        }
        if (j == n) ans = i-n+1;
        ans==-1?puts("0"):printf("%d\n",ans);
        
    }
}
