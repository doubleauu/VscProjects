// 思路：题目问权值在范围内的路径数量，可以使用dfs进行搜索遍历；
// 易得当前不为零时，前进一定变大
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

int main() {
 	ll n, l, r;
 	cin >> n >> l >> r;
 	string s;
 	cin >> s;
 	s = " " + s;  // 实现下标从1访问；
 	vector<vector<ll> > a(n+1);
 	for(ll i = 1; i < n; i++) {
 		ll t1, t2;
 		cin >> t1 >> t2;
 		a[t1].pb(t2);
 		a[t2].pb(t1);
 	}
 	
 	ll ans = 0;
 	// dfs深搜，直接暴力遍历每一个起点的所有路径：
 	function<void(ll,ll,ll,ll)> dfs = [&](ll fu, ll now, ll sz, ll len) {
 		if(sz > r) return;
 		if(len > 0 && sz >= l && sz <= r) ans++;
 		for(ll i : a[now]) {
 			if(i == fu) continue;
 			dfs(now,i,sz*2+(s[i]-'0'),len+1);
 		}
 	};
 	
 	for(ll i = 1; i <= n; i++) {
 		dfs(i,i,s[i]-'0',0);
 	}
 	cout << ans << endl;
 	
}