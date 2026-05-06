#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
/*
url: https://www.luogu.com.cn/problem/B2164
组合数模板问题
记得模意义下使用快速幂和乘法逆元
*/
ll fastPow(ll a, ll b) {
    ll ans = 1, base = a;
    while(b) {
        if(b&1) ans = ans*base%mod;
        base = base*base%mod;
        b >>= 1;
    }
    return ans;
}
ll inv(ll n) {
    return fastPow(n,mod-2);
}
ll fac(ll n) {
    if(n==0) return 1;
    return n*fac(n-1)%mod;
}
void solve() {
	int n, m;
    cin >> n >> m;
    cout << fac(n)*inv(fac(n-m))%mod*inv(fac(m))%mod << endl;

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