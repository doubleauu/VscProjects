// Problem: 时不时使使用玉米加农炮掩饰害羞的邻座艾莉同学
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/H
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll> > a(n+1,vector<ll>(m+1));
	vector<vector<ll> > b(n+1,vector<ll>(m+1));
	ll maxn = INT_MIN;
	ll x, y;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			// b[i][j]+=a[i][j];
			// for(int k = max(1,i-2); k <= min(n,i+2); k++) {
				// if(k==i) continue;
				// b[k][j] += a[i][j];
				// if(b[k][j] > maxn) {
					// maxn = b[k][j];
					// x = k, y = j;
				// }
			// }
			// for(int k = max(1,j-2); k <= min(m,j+2); k++) {
				// if(k==j) continue;
				// b[i][k] += a[i][j];
				// if(b[i][k] > maxn) {
					// maxn = b[i][k];
					// x = i, y = k;
				// }
			// }
			for(int p = max(1,i-1); p <= min(n,i+1); p++) {
				for(int q = max(1,j-1); q <= min(m,j+1); q++) {
					b[p][q] += a[i][j];
					if(b[p][q] > maxn) {
						maxn = b[p][q];
						x = p, y = q;
					}
				}
			}
			if(i-2>=1) {
				b[i-2][j]+=a[i][j];
				if(b[i-2][j]>maxn) {
					maxn = b[i-2][j];
					x = i-2, y = j;
				}
			}if(i+2<=n) {
				b[i+2][j]+=a[i][j];
				if(b[i+2][j]>maxn) {
					maxn = b[i+2][j];
					x = i+2, y = j;
				}
			}if(j-2>=1) {
				b[i][j-2]+=a[i][j];
				if(b[i][j-2]>maxn) {
					maxn = b[i][j-2];
					x = i, y = j-2;
				}
			}if(j+2<=m) {
				b[i][j+2]+=a[i][j];
				if(b[i][j+2]>maxn) {
					maxn = b[i][j+2];
					x = i, y = j+2;
				}
			}
			// if(i-2>=1) b[i-2][j]+=a[i][j];
			// if(i+2<=n) b[i+2][j]+=a[i][j];
			// if(j-2>=1) b[i][j-2]+=a[i][j];
			// if(j+2<=m) b[i][j+2]+=a[i][j];
			
		}
	}
	// cerr << b[2][2] << endl;
	while(q--) {
		int i, j, z;
		cin >> i >> j >> z;
		for(int p = max(1,i-1); p <= min(n,i+1); p++) {
			for(int q = max(1,j-1); q <= min(m,j+1); q++) {
				b[p][q] += z;
				// cerr << p << " " << q << " " << b[p][q] << endl;
				if(b[p][q] > maxn) {
					maxn = b[p][q];
					x = p, y = q;
				}
			}
		}
		// cerr << endl;
		if(i-2>=1) {
			b[i-2][j]+=z;
			if(b[i-2][j]>maxn) {
				maxn = b[i-2][j];
				x = i-2, y = j;
			}
		}if(i+2<=n) {
			b[i+2][j]+=z;
			if(b[i+2][j]>maxn) {
				maxn = b[i+2][j];
				x = i+2, y = j;
			}
		}if(j-2>=1) {
			b[i][j-2]+=z;
			if(b[i][j-2]>maxn) {
				maxn = b[i][j-2];
				x = i, y = j-2;
			}
		}if(j+2<=m) {
			b[i][j+2]+=z;
			if(b[i][j+2]>maxn) {
				maxn = b[i][j+2];
				x = i, y = j+2;
			}
		}
		// cout << maxn << endl;
		cout << x << " " << y << endl;
	}
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