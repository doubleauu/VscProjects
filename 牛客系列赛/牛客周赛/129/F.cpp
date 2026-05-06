// Problem: 小红的魔法树探险
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127264/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;

ll fastPow(ll a, ll b) {
	ll base = a;
	ll ans = 1;
	while(b > 0) {
		if(b & 1) {
			ans = ans * base % p;
		}
		base = base * base % p;
		b >>= 1;
	}
	return ans;
}

int main() {
 	 int n;
 	 cin >> n;
 	 vector<vector<int>> a(n+1);
 	 for(int i = 1; i < n; i++) {
 	 	int t1, t2;
 	 	cin >> t1 >> t2;
 	 	a[t1].pb(t2);
 	 	a[t2].pb(t1);
 	 }
 	 vector<int> f(n+1);
 	 f[1] = 1;
 	 
 	 function<void(int,int)> dfs = [&](int fu,int now) {
 	 	for(int i : a[now]) {
 	 		if(i == fu) continue;
 	 		f[i] = f[now]*fastPow(2,p-2)%p;
 	 		dfs(now,i);
 	 	}
 	 };
 	 dfs(2,1);
 	 ll ans = 1;
 	 for(int i = 1; i <= n; i++) {
 	 	ans = (ans + i*f[i]%p)%p;
 	 }
 	 cout << ans << endl;
 	 
}