// CCO '08 Day 1 Problem 3 - Mobile
// http://wcipeg.com/problem/ccc08s2p3

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100001;
struct mob {
      int l,r;
}mobsa[maxn],mobsb[maxn];
int n,a,b,m;

bool dfs(int a, int b) {
      int al = mobsa[a].l, bl = mobsb[b].l, ar = mobsa[a].r, br = mobsb[b].r;
      if (al > 0 && bl > 0 && ar > 0 && br > 0) {
            if (dfs(al,bl) && dfs(ar,br)) return 1;
            if (dfs(ar,bl) && dfs(al,br)) return 1;
      }
      if (al < 0 && bl > 0) {
            if (al == br && dfs(ar,bl)) return 1;
      }
      if (al < 0 && br > 0) {
            if (al == bl && dfs(ar,br)) return 1;
      }
      if (ar < 0 && bl > 0) {
            if (ar == br && dfs(al,bl)) return 1;
      }
      if (ar < 0 && br > 0) {
            if (ar == bl && dfs(al,br)) return 1;
      }
      if (al < 0 && bl <0 && ar < 0 && br < 0)  {
            if (al == bl && ar == br) return 1;
            if (al == br && ar == bl) return 1;
      }
      return 0;
}
int main() {
      scanf("%d",&n);
      for (int i = 1;i<=n;i++) {
            scanf("%d%d",&mobsa[i].l,&mobsa[i].r);
      }
      scanf("%d",&m);
      for (int i = 1;i<=m;i++) {
            scanf("%d%d",&mobsb[i].l,&mobsb[i].r);
      }

      if (n==m && dfs(1,1)) printf("Fred and Mary might have the same mobile.\n");
      else printf("Fred and Mary have different mobiles.\n");
}
