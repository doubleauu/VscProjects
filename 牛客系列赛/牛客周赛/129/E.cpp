// Problem: 小红的多维空间冒险
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127264/E
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
const int MOD = 1e9+7;
const int N = 2e5+5;

ll pre[N];
ll pret[N];

ll fastPow(ll a, ll b) {
	ll base = a;
	ll ans = 1;
	while(b > 0) {
		if(b & 1) {
			ans = ans * base % MOD;
		}
		base = base * base % MOD;
		b >>= 1;
	}
	return ans;
}

int main() {
 	int n;
 	cin >> n;
 	pre[0] = 1;
 	pret[0] = 1;
 	for(int i = 1; i <= n; i++) {
 		pre[i] = pre[i-1]*2%p;
 		pret[i] = pret[i-1]*i%p;
 	}
 	
 	
 	
 	for(int i = 1; i <= n; i++) {
 		// int t = i;
 		// ll ans = 1;
 		// ll tans = 1;
 		// int ti = 0;
 		// while(t--) {
 			// ans = ans * (n-ti)%p;
 			// tans = tans * (1+ti) % p;
 			// ti++;
 		// }
 		// cout << ans*fastPow(tans,p-2)%p*pre[i-1]%p*pre[n-i]%p << " " ;
 		cout << pret[n]*fastPow(pret[n-i],p-2)%p*fastPow(pret[i],p-2)%p*pre[i-1]%p*pre[n-i]%p << " " ;
 	}
}