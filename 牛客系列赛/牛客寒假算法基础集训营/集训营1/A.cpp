// Problem: A+B Problem
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/A
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 998244353;
const int N = 1e6+5;

ll fastPow(ll a, ll b) {
	ll base = a;
	ll ans = 1;
	while(b > 0) {
		if(b & 1) {
			ans = ans * base % mod;
		}
		base = base * base % mod;
		b >>= 1;
	}
	return ans;
}

ll inv[105];
void xianxing(ll n, ll p) {
    inv[1] = 1;
    for(ll i = 2; i <= n; i++) {
        inv[i] = ((-(p/i) * inv[p%i])%p+p)%p;
    }
}

int main() {
	xianxing(105,mod);
	
 	int t;
 	cin >> t;
 	while(t--) {
 		int n;
 		cin >> n;
 		vector<ll> p(8); //亮的概率
 		vector<ll> pp(8); // 不亮的概率
 		for(int i = 1; i <= 7; i++) {
 			cin >> p[i];
 			pp[i] = 100-p[i];
 			p[i] = p[i]*inv[100]%mod;
 			pp[i] = pp[i]*inv[100]%mod;
 		}
 		vector<ll> pre(10);  // 单个表示为 i 的概率
 		pre[0] = p[1]*p[2]%mod*p[3]%mod*pp[4]%mod*p[5]%mod*p[6]%mod*p[7]%mod;
 		pre[1] = pp[1]*pp[2]%mod*p[3]%mod*pp[4]%mod*pp[5]%mod*p[6]%mod*pp[7]%mod;
 		pre[2] = p[1]*pp[2]%mod*p[3]%mod*p[4]%mod*p[5]%mod*pp[6]%mod*p[7]%mod;
 		pre[3] = p[1]*pp[2]%mod*p[3]%mod*p[4]%mod*pp[5]%mod*p[6]%mod*p[7]%mod;
 		pre[4] = pp[1]*p[2]%mod*p[3]%mod*p[4]%mod*pp[5]%mod*p[6]%mod*pp[7]%mod;
 		pre[5] = p[1]*p[2]%mod*pp[3]%mod*p[4]%mod*pp[5]%mod*p[6]%mod*p[7]%mod;
 		pre[6] = p[1]*p[2]%mod*pp[3]%mod*p[4]%mod*p[5]%mod*p[6]%mod*p[7]%mod;
 		pre[7] = p[1]*pp[2]%mod*p[3]%mod*pp[4]%mod*pp[5]%mod*p[6]%mod*pp[7]%mod;
 		pre[8] = p[1]*p[2]%mod*p[3]%mod*p[4]%mod*p[5]%mod*p[6]%mod*p[7]%mod;
 		pre[9] = p[1]*p[2]%mod*p[3]%mod*p[4]%mod*pp[5]%mod*p[6]%mod*p[7]%mod;
 		
 		vector<ll> a(n+1);   // 整体表示为 i 的概率；
 		for(int i = 0; i <= n; i++) {
 			// 分别取四位数字；
 			int t1 = i%10;
 			int t2 = i/10%10;
 			int t3 = i/100%10;
 			int t4 = i/1000%10;
 			// cout << t4 << " " << t3 << " " << t2 << " " << t1 << endl;
 			a[i] = pre[t4]*pre[t3]%mod*pre[t2]%mod*pre[t1]%mod;
 		}
 		ll ans = 0;
 		for(int i = 0; i <= n; i++) {
 			ans = (ans + a[i]%mod*a[n-i]%mod)%mod;
 		}
 		cout << ans << endl;
 	}
}