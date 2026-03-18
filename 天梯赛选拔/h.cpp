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
	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> a(n+2);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<ll> dp(n+2,1e18);
	dp[0] = 0;
	// 题意为修改前端和后端区间为目标值
	// 动态规划，状态为以 a[i] 为终点的区间的最小值， 转移的关键在于a[i] 是否修改
	// 先正着跑一遍，再倒着跑一遍，找到交界点
	for(int i = 1 ; i <= n; i++) {
		dp[i] = min(dp[i-1]+a[i], i*l);
	}
	ll ans = 1e18, pre = 0;
	for(int i = n+1; i >= 1; i--) {
		pre = min(pre+a[i], (n-i+1)*r);
		ans = min(ans,pre+dp[i-1]);
	}
	cout << ans;
	
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