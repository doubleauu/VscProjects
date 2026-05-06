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
url: https://codeforces.com/gym/106495/problem/J
有 n 个数字，挑选三个组成偶数，问有多少种情况；
两个数相加，不是偶数的只有一种情况：一个奇数一个偶数
进一步发现: 三个元素只能有两种情况：三个偶数，或则一个偶数两个奇数
则是一个组合数问题；
完全不需要组合数公式，因为我们的 m 很小，直接枚举即可，否则会tle
（t很大，每次算阶乘 O(n) 必定会超时）
*/

ll t2, t3;
ll fac(ll n) {
    ll res = 1;
    for(int i = 1; i <= n; i++) {
        res = res * i % mod;
    }
    return res;
}
ll fastPow(ll a, ll b) {
    ll ans = 1;
    ll base = a;
    while(b){
        if(b&1) ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}
ll C(ll n, ll m) {
    if(n==m) return 1;
    if(n < m) return 0;
    // return (fac(n)*fastPow(fac(n-m),mod-2)%mod)*fastPow(fac(m),mod-2)%mod;
    if(m==1) return n;
    if(m==2) return n*(n-1)%mod*t2%mod;
    if(m==3) return n*(n-1)%mod*(n-2)%mod*t3%mod;
    return 0;
}
void solve() {
	int n;
    cin >> n;
    int odd = (n%2==0 ? n/2 : n/2+1), even = n/2;
    cout << (C(even,3)+C(even,1)*C(odd,2)%mod)%mod << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    t2 = fastPow(2,mod-2);
    t3 = fastPow(6,mod-2);
    while(T--) {
        solve();
    }
    return 0;
}