#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 998244353;
int N = 1e6+5;
/*
url: https://www.luogu.com.cn/problem/B3717
依旧组合数问题，但是是多次提问版本
为了避免多次求幂或则逆元，我们直接提前预处理两个数组：阶乘和阶乘逆元；
然后 O(1) 得到答案；否则会在每次求组合数是调用三次阶乘和两次逆元，复杂度更高；
注意 fac[0] = fac[1] = ifac[0] = ifac[1]都要设置为 1;
*/
ll res = 0;
vector<ll> fac, ifac;
ll fastPow(ll a, ll b) {
    ll ans = 1, base = a;
    while(b) {
        if(b&1) ans = ans*base%mod;
        base = base*base%mod;
        b >>= 1;
    }
    return ans;
}
ll inv(int n) {
    return fastPow(n,mod-2);
}
void solve() {
	int n, m;
    cin >> n >> m;
    ll ans = fac[n]*ifac[n-m]%mod*ifac[m]%mod;
    if(n<m) ans = 0;
    res ^= ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    // int N;
    cin >> N;
    fac.assign(N+1,0);
    ifac.assign(N+1,0);
    fac[0] = fac[1] = 1;
    ifac[0] = ifac[1] = 1;
    for(int i = 2; i <= N; i++) {
        fac[i] = fac[i-1]*i%mod;
        ifac[i] = inv(fac[i]);
    }
    while(T--) {
        solve();
    }
    cout << res << endl;
    return 0;
}