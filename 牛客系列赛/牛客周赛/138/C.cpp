// Problem: 小苯的数位排序
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/131111/C
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
ll to(ll n) {
	ll t = 0;
	while(n > 0) {
		t += n%10;
		n /= 10;
	}
	return t;
}
void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n+1);
	ll ans = 0;
	
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(ll i = n-1; i >= 1; i--) {
		if(a[i]>a[i+1]) {
			while(a[i]>a[i+1]) {
				if(to_string(a[i]).size()==1) {
					cout << -1 << endl;
					return;
				}
				a[i] = to(a[i]);
				ans++;
			}
		}
	}
	cout << ans << endl;
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