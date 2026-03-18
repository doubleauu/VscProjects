// Problem: AT_abc362_d [ABC362D] Shortest Path 3
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_abc362_d
// Memory Limit: 1024 MB
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
const ll mod = 1e9+7;
const ll N = 1e6+5;
// ll n,m,k,x,y,num,op,sum,cnt,res,ans;

struct M {
	ll v;
	ll val;
};

struct N {
	ll p;
	ll val;
};

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n+1);
	vector<vector<M>> b(n+1);
	
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while(m--) {
		ll i, j, k;
		cin >> i >> j >> k;
		M m1; m1.v = j, m1.val = k;
		M m2; m2.v = i, m2.val = k;
		b[i].pb(m1);
		b[j].pb(m2);
	}
	vector<ll> ans(n+1);
	ans[1] = a[1];
	vector<ll> t(n+1,INT64_MAX); // 记录当前每个节点的状态；
	ll pos = 1; // 标记当前位置；
	for(ll i = 2; i <= n; i++) {
		for(auto j : b[pos]) {
			if(ans[j.v]) continue;
			if(ans[pos]+j.val+a[j.v] < t[j.v]) {
				t[j.v] = ans[pos] + j.val + a[j.v];
			}
		}
		ll minn = INT64_MAX;
		for(ll j = 2; j <= n; j++) {
			if(ans[j]) continue;
			if(t[j] < minn) {
				minn = t[j];
				pos = j;
			}
		}
		ans[pos] = minn;
	}
	for(ll i = 2; i <= n; i++) {
		cout << ans[i] << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}