// Problem: 小L的数组
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/H
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
	int n;
	cin >> n;
	vector<ll> a(n+1), b(n+1);
	vector<ll> pre(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		pre[i] = pre[i-1]^b[i];
	}
	ll ans = pre[n];
	for(int i = 1; i <= n; i++) {
		if((max(1LL*0,(pre[i-1]-a[i]))^ans^pre[i]) > ans) {
			ans = max(1LL*0,(pre[i-1]-a[i]))^ans^pre[i];
		}
	}
	cout << ans << endl;
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