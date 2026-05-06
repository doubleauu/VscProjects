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
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
// 回顾乘法逆元的知识
// 逆元相关运算容易溢出，每次加法，乘法运算后必须取模；
// 参考高中数学，我们算出一张卡片也没有抽到的情况，然后取反即可；

ll fastPow(ll a, ll b) {
	ll ans =  1;
	ll base = a;
	while(b>0) {
		if(b&1) ans = ans*base%mod;
		base = base*base%mod;
		b >>= 1;
	}
	return ans;
}

ll inv(ll n) {
	return fastPow(n,mod-2);
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n+1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
    	cin >> b[i];
    }
	ll tans = 1;
    for(int i = 1; i <= n; i++) {
    	tans = tans*(((a[i]-b[i])*inv(a[i]))%mod)%mod;
    }
    cout << (1-tans+mod)%mod << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}