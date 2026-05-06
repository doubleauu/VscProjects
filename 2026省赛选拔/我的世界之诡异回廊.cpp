#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0,+1};
int dy[] = {+1,0};

vector<vector<ll>> a, ct, resa, resb;
int n, m;
ll ans = -2e18;
void dfs(int ax, int ay, int bx, int by, ll resa, ll resb) {
    if(ax > n || ay > m) return;
    // cout << ax << " " << ay << " " << bx << " " << by << " " << resa << " " << resb << endl;
    if(resa-resb < ct[ax][ay]) return;
    ct[ax][ay] = resa-resb;
    ans = max(ans,resa-resb);
    // if(ay>=m) return;
    dfs(ax,ay+1,bx,by-1,resa+a[ax][ay+1],resb+a[bx][by-1]);  // 右移
    // if(ax>=n) return;
    dfs(ax+1,ay,bx+1,by,resa+a[ax+1][ay],resb+a[bx+1][by]);  // 下移
}

int iy(int y) {
    return m+1-y;
}
void solve() {
    cin >> n >> m;
    a.assign(n+2,vector<ll>(m+2));
    ct.assign(n+2,vector<ll>(m+2,-2e18));
    resa.assign(n+2,vector<ll>(m+2,-2e18));
    resb.assign(n+2,vector<ll>(m+2,-2e18));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    queue<int> qx, qy;
    qx.push(1); qy.push(1);
    ct[1][1] = a[1][1]-a[1][m];
    resa[1][1] = a[1][1];
    resb[1][1] = a[1][m];
    while(!qx.empty()) {
        int x = qx.front(), y = qy.front();
        qx.pop(), qy.pop();
        for(int i = 0; i < 2; i++) {
            int tx=x+dx[i], ty = y+dy[i];
            if(tx > n || ty > m) continue;
            ll tresa = resa[x][y]+a[tx][ty];
            ll tresb = resb[x][y]+a[tx][iy(ty)];
            if(tresa-tresb > ct[tx][ty]) {
                ct[tx][ty] = tresa-tresb;
                ans = max(ans,ct[tx][ty]);
                resa[tx][ty] = tresa;
                resb[tx][ty] = tresb;
                qx.push(tx); qy.push(ty);
            }
        }
    }
    
    // dfs(1,1,1,m,a[1][1],a[1][m]);
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}