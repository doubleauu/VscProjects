// Problem: 小苯的序列涂色
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/130843/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n+1), pre(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i-1]^a[i];
	}
	
	// 表示从 1 染色到当前区间所需要的最小代价
	vector<ll> dp(n+1,2e18);
	dp[0] = 0;
	for(int r = 1; r <= n; r++) {
		ll t = 2e18; // 区间代价,不一定是[l,r]，也可能是[<l,r]；
		for(int l = 1; l <= r; l++) {
			t = min(t,pre[r]^pre[l-1]);
			dp[r] = min(dp[r],dp[l-1]+t);
		}
	}
	cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}