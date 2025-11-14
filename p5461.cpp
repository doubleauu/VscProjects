/**
 * @brief: 二维数组四分，左上角赦免为0，其余为1，输出结果二维数组
 */
#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int l, int r, vector<vector<int>>& a) {  //l表示行的起点，r表示列，l和r实现了每次区间的移动
    if(x == 2) {
        a[l][r] = 0;
        return;
    }
    for(int i = l; i < l+x/2; i++) {
        for(int j = r; j < r+x/2; j++) {
            a[i][j] = 0;
        }
    }
    dfs(x/2, l+x/2, r, a);
    dfs(x/2, l, r+x/2, a);
    dfs(x/2, l+x/2, r+x/2, a);
}

int main() {
    int n;
    scanf("%d", &n);
    int m = 1;  //记录边长
    for(int i = 0; i < n; i++) {
        m <<= 1;  //2的几次方就左移几次
    }
    vector<vector<int>> a(m+1,vector<int> (m+1,1)); //使用vector构造函数初始化全为1
    dfs(m,1,1,a);
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}