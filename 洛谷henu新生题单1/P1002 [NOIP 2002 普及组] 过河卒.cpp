/**
 * @brief: 求过河卒从a点到b点的路径数目，避开马的控制点
 * @details: bfs中每个点只能过一次，而此题目中过河卒可以多次通过同一个点，应当使优化后bfs或则dp，但考虑复杂度，推荐dp
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[]{0,1,1,-1,-1,2,2,-2,-2};
int dy[]{0,2,-2,2,-2,1,-1,1,-1};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<ll>> ans(n+1, vector<ll>(m+1,0));
    vector<vector<ll>> judge(n+1, vector<ll>(m+1,0));  //标记马的控制点

    for(int i = 0; i < 9; i++) {
        int tx = x+dx[i], ty = y+dy[i];
        if(tx>=0 && tx<=n && ty>=0 && ty <=m) judge[tx][ty] = -1;
    }

    //赋初始值
    ans[0][0] = judge[0][0] == 0 ? 1 : 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if((i==0 && j==0)) continue;  //跳过初始点
            if(judge[i][j] == 0) {  //跳过马的判断点
                // if(i == 0 || j == 0) ans[i][j] = 1;  //边界上点路径均为1；（不要特殊处理，使用递推即可）
                if(i == 0) ans[i][j] = ans[i][j-1];
                if(j == 0) ans[i][j] = ans[i-1][j];
                if(i != 0 && j != 0){
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];  //一般状态转移方程
                }
            }
        }
    }
    cout << ans[n][m];

}












#if 0
//尝试使用优化后的bfs做，队列中有几个nm就有几条路径，但是内存和时间爆炸
#include <bits/stdc++.h>
using namespace std;

int dx[]{1,1,2,2,-1,-1,-2,-2};
int dy[]{2,-2,1,-1,2,-2,1,-1};
int ax[]{1,0};
int ay[]{0,1};
queue<int> qx, qy;
long long ans;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> visit(n+1,vector<int>(m+1,0));

    //标记不能走的位为-1；
    visit[x][y] = -1;
    for(int i = 0; i < 8; i++) {
        int tx = x+dx[i], ty = y+dy[i];
        if(tx>=0 && tx<=n && ty>=0 && ty<=m) {
            visit[tx][ty] = -1;
        }
    }

    if(visit[0][0] != -1) {
        qx.push(0); qy.push(0);
    }

    while(!qx.empty()) {
        int tx = qx.front(), ty = qy.front();
        qx.pop(); qy.pop();
        for(int i = 0; i < 2; i++) {
            int a = tx+ax[i], b = ty+ay[i];
            if(a == n && b == m) {
                ans++; continue;
            }
            if(a>=0 && a<=n && b>=0 && b<=m && visit[a][b]==0) {
                qx.push(a); qy.push(b);
            }
        }
    }
    cout << ans;
}
#endif