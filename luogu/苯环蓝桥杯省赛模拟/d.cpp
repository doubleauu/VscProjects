// Problem: P15966 合成西瓜
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P15966?contestId=314564
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
const int mod = 998244353;
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;

ll fastpow(ll a, ll b, ll p) {
	ll ans = 1;
	ll base = a;
	while(b>0) {
		if(b&1) ans = ans*base%p;
		base = base*base%p;
		b >>= 1;
	}
	return ans;
}
void solve() {
	ll x, y;
	cin >> x >> y;
	if(x <= y) {
		cout << 1 << endl;
		return;
	}
	// ll a = 1, pre = 1;
	// vector<ll> a(x+1), pre(x+1);
	// a[y+1] = 1;
	// pre[y+1] = 1;
// 	
	// for(int i = y+2; i <= x; i++) {
		// a = (pre+1)%mod;
		// pre = (pre+a)%mod;
	// }
	// cout << a*(y+1)%mod << endl;
	cout << (y+1)*fastpow(2,x-y-1,mod)%mod << endl;
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