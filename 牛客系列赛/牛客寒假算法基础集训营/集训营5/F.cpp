// Problem: 智乃的算法竞赛群友
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120565/F
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
const int N = 1e9+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
void solve() {
	int W, a, b;
	cin >> W >> a >> b;
	if(W < 2) {
		cout << 0 << endl;
		return;
	}
	vector<array<ll, 2>> f(3);
	f[0][0] = 7, f[1][1] = a;
	f[1][0] = 2, f[1][1] = b;
	f[2][0] = 8, f[1][1] = a+b;
	vector<ll> dp(N+1, 1e14);
	for (const auto& [w, v] : f) {
		for (int j = N; j >= v; j--) {
			dp[j] = min(dp[j], dp[j - v] + w);
		}
	}
	for (int i = N; i >= 0; i--) {
		if (dp[i] && dp[i] <= W) {
			cout << i << endl;
			return;
		}
	}
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