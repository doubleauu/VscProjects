// Problem: 智乃的果子
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120565/D
// Memory Limit: 1024 MB
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
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
vector<ll> a;
void solve() {
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		a.insert(a.end(),t1,t2);
	}
	sort(a.begin(),a.end(),greater<int>());
	ll ans = 0;
	while(a.size()>1) {
		sort(a.begin(),a.end(),greater<int>());

		ll t1 = a.back(); a.pop_back();
		ll t2 = a.back(); a.pop_back();
		a.pb(t1+t2);
		ans = (ans+(t1+t2)%mod)%mod;
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