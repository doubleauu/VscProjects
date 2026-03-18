#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
void solve() {
	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1==x2&&y1==y2) {
		cout << 0;
		return;
	}
	vector<string> a(n+1);
	vector<vector<int>> res(n+1, vector<int>(m+1));
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = " " + a[i];
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == '*') res[i][j] = 1; // 1 障碍物
		}
	}
	vector<vector<int>> v(n+1, vector<int>(m+1)); // 1 为走过的
	vector<vector<int>> ans(n+1, vector<int>(m+1)); //记录最短步数；
	queue<int> qx, qy;
	qx.push(x1); qy.push(y1);
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};
	while(!(qx.empty()&&qy.empty())) {
		int tx = qx.front(), ty = qy.front();
		qx.pop(); qy.pop();
		for(int i = 0; i < 4; i++) {
			int ttx = tx + dx[i], tty = ty + dy[i];
			if(ttx>=1 && tty>=1 && ttx <= n && tty<=m && res[ttx][tty]==0 && v[ttx][tty]==0 ){
				qx.push(ttx), qy.push(tty);
				v[ttx][tty] = 1;
				// if(ans[ttx][tty]!=0) ans[ttx][tty] = min(ans[ttx][tty],ans[tx][ty]+1);
				ans[ttx][tty] = ans[tx][ty]+1;
				if(ttx==x2 && tty==y2) {
					cout << ans[ttx][tty];
					return;
				}
			}
		}
	}
	cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}