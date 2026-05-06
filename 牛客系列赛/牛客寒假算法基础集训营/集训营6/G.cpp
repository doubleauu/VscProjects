// Problem: 小L的散步
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
	int n, m, len;
	cin >> n >> m >> len;
	vector<ll> a(n+1), b(m+1), pre(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = a[i] + pre[i-1];
	}
	ll l = 0, r = len;
	bool y = 0;
	if(r > pre[1]) y =1;
	// cout << pre[n+2] << endl;
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		l += b[i];
		r += b[i];
		if(l >= pre[n]) continue;
		auto itl = lower_bound(pre.begin()+1,pre.end(),l)-pre.begin();
		if(pre[itl]==l) itl++;
		auto itr = lower_bound(pre.begin()+1,pre.end(),r)-pre.begin();
		// cout << itl << " " << itr << endl;
		// if(*itr == r) itr--;
		// cout << *itl << endl;
		// cout << (int)(itl-pre.begin()) << " " << (int)(itr-pre.begin()) << endl;

		if(itl != itr) {
			// cout << (int)(itl-pre.begin()) << " " << (int)(itr-pre.begin()) << endl;
			// cout << "YES" << endl;
			y = 1;
			// return;
		}
		
	}
	if(y) cout << "YES" << endl;
	else cout << "NO" << endl;
	
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