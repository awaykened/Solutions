// DMOPC '14 Contest 3 P5 - Not Enough Servers!
// https://dmoj.ca/problem/dmopc14c3p5

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int pos = 1,r,c,cnt,best = 999999;
char ch;
vector<int> grid[21];
int moves[21],bestm[21];
bool flag[51];

void find(int &pos) {
    if (cnt >= best) return;
    if (pos == r+1) {
        for (int i = 1;i<=r;i++)
            bestm[i] = moves[i];
        best = min(best,cnt);
        return;
    }
    if (!grid[pos].size()) {
        moves[pos] = -1;
        pos ++;
        find(pos);
        pos --;
    }
    else {
        for (int i = 0;i<grid[pos].size();i++) {
            int check = grid[pos][i];
            if (!flag[check]) {
                moves[pos] = check;
                cnt ++; pos ++;
                flag[check] ^= 1;
                find(pos);
                flag[check] ^= 1;
                cnt --; pos --;
            } else {
                moves[pos] = -1;
                pos ++;
                find(pos);
                pos --;
            }
        }
    }
}
int main() {
    scanf("%d%d",&r,&c);
    for (int i = 1;i<=r;i++)
        moves[i] = -1;
    for (int i = 1;i<=r;i++)
        for (int j = 1;j<=c;j++) {
            scanf(" %c",&ch);
            if (ch == 'X')
                grid[i].push_back(j);
        }
    find(pos);
    printf("%d\n",max(best,1));
    if (!best) cout << 1 << endl;
    else {
        for (int i =1;i<=r;i++)
            if (bestm[i]!=-1)
                printf("%d ",bestm[i]);
        cout << endl;
    }
    
}
