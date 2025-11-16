/**
 * @brief: 马的遍历问题，使用广度优先算法；
 * @details: 定义全局变量，回忆数组的初始化函数使用，学习队列结构；
 */
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};
int ans[405][405];
int v[405][405];
queue<int> qx, qy;
int n, m, x, y;

int main() {
    fill(&ans[0][0], &ans[0][0]+405*405, -1);  //初始化为-1；
    memset(v,-1,sizeof(v));  //初始化为-1；
    scanf("%d%d%d%d",&n, &m, &x, &y);
    ans[x][y] = v[x][y] = 0;
    qx.push(x); qy.push(y);
    while(!qx.empty() && !qy.empty()) {
        int x = qx.front(), y = qy.front();  
        qx.pop(); qy.pop();
        for(int i = 0; i < 8; i++) {
            int tx = x+dx[i], ty = y+dy[i];  //临时变量，不要改变用于整个for循环的x,y
            if((tx>0 && tx<=n) && (ty>0 && ty<=m) && v[tx][ty] == -1) {   //如果未越界且未访问过
                ans[tx][ty] = ans[x][y] + 1;
                qx.push(tx); qy.push(ty);
                v[tx][ty] = 0;  //标记访问过为0；
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}


#if 0
/**
 * @brief: 马的遍历，计算马到棋盘任意一点的步数，使用优化后的深度优先搜索
 */
#include <bits/stdc++.h>
using namespace std;

int a[500][500];
int n, m, x, y;
int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};


void fun(int x, int y) {
    if(x < 1+1 || x > n+1 || y < 1+1 || y > m+1) return;
    for(int i = 0; i < 8; i++) {
        if(a[x+dx[i]][y+dy[i]] == -1 || (a[x+dx[i]][y+dy[i]] != -1 && a[x+dx[i]][y+dy[i]] > a[x][y]+1) ) {
            a[x+dx[i]][y+dy[i]] = (a[x][y]+1);
            fun(x+dx[i],y+dy[i]);  //需要先走完一遍再递归？
        }else {
            continue;
        }
    }
    // a[x+1][y+2]=a[x+1][y-2]=a[x-1][y+2]=a[x-1][y-2]=(a[x][y]+1);
    // a[x+2][y+1]=a[x+2][y-1]=a[x-2][y+1]=a[x-2][y-1]=(a[x][y]+1);
    // fun(x+1,y+2);
    // fun(x+1,y-2);
    // fun(x-1,y+2);
    // fun(x-1,y-2);
    // fun(x+2,y+1);
    // fun(x+2,y-1);
    // fun(x-2,y+1);
    // fun(x-2,y-1);
}

int main() {
    fill(&a[0][0],&a[0][0] + 500*500, -1); //初始化数组为-1
    scanf("%d%d%d%d", &n, &m ,&x, &y);
    a[x+1][y+1] = 0;
    fun(x+1,y+1);
    for(int i = 1+1; i <= n+1; i++) {
        for(int j = 1+1; j <= m+1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#endif
