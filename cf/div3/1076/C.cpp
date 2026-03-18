// Problem: C. Replace and Sum
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//@brief:
//@details:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll n, q;
		cin >> n >> q;
		vector<ll> a(n+1), b(n+1);
		for(ll i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(ll i = 1; i <= n; i++) {
			cin >> b[i];
			if(a[i] < b[i]) a[i] = b[i];
		}
		// for(ll i = 1; i <= n; i++) {
			// if(a[i] < b[i]) {
				// a[i] = b[i];
			// }
		// }
		vector<ll> maxn(n+1);
		vector<ll> preSum(n+2);  // 使用前缀和加快查询；
		ll t = INT_MIN;
		for(ll i = n; i >= 1; i--) {
			t = max(t, a[i]);
			maxn[i] = t;
			preSum[i] = maxn[i]+preSum[i+1];
		}
		while(q--) {
			ll l, r;
			cin >> l >> r;
			
			// for(ll i = l; i <= r; i++) {
				// if(i < n && a[i] < a[i+1]) {
					// a[i] = a[i+1];
				// }
			// }
			
			// ll sum = 0;
			// for(ll i = l; i <= r; i++) {
				// sum += maxn[i];
			// }
			cout << preSum[l] - preSum[r+1] << " ";
		}
		cout << endl;
	}
}