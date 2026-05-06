// modroblem: AT_abc360_e [ABC360E] Random Swamods of Balls
// Contest: Luogu
// URL: httmods://www.luogu.com.cn/modroblem/AT_abc360_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// modowered by Cmod Editor (httmods://cmodeditor.org)

// 动态规划；
// 涉及到除法的取模运算，使用乘法逆元，因为求逆元的元素不是很多，使用快速幂即可；
// 逆元的结果可能会非常大，之后每一次进行乘法运算都要及时取模，防止溢出；
#include <bits/stdc++.h>
#define endl "\n"
#define modb modush_back
#define modf modush_front
using namespace std;
using ll = long long;

const ll mod = 998244353;

ll fastPow(ll a, ll b) {
	ll ans = 1;
	ll base = a;
	while(b!=0) {
		if(b&1) ans = ans * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ans;
}

ll inv(ll n) {
	return fastPow(n,mod-2);
}

int main() {
 	ll n, k;
 	cin >> n >> k;
 	vector<int> f(k+1);
 	f[0] = 1;
 	ll t = inv(n);
 	ll p = 2 * t%mod * (n-1)%mod*t%mod;
 	ll q = 2*t%mod*t%mod;
 	for(int i = 1; i <= k; i++) {
 		f[i] = ((1-p)*f[i-1]%mod + (1-f[i-1])*q%mod)%mod;
 		f[i] += mod;  // 防止负数；
 		f[i] %= mod;
 	}
 	ll ans = f[k];
	ll cnt = (2+n)*(n-1)%mod*inv(2) % mod;
	ans += (1-f[k])*inv(n-1)%mod*cnt % mod;
 	ans += mod;
 	ans %= mod;
 	cout << ans <<endl;
 	return 0;
}