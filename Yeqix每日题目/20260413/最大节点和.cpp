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
const int N = 1e6+5;
/*
url: https://ac.nowcoder.com/acm/contest/112692/H
数据范围是1e18，肯定是要找规律的；
根据题中例子发现n=5的结果刚好是n=4结果的递推，考虑递推关系
找到递推关系了发现不会求通项公式了wc，难
*/
ll fastPow(ll a, ll b) {
    ll ans = 1;
    ll base = a;
    while(b) {
        if(b&1) ans = ans*base%mod;
        base = base*base%mod;
        b >>= 1;
    }
    return ans;
}
void solve() {
	ll n;
    cin >> n;
    // cout << fastPow(2,n+2) << endl;
    if(n%2==0) cout << (fastPow(2,n+2)-1-3)*fastPow(6,mod-2)%mod << endl;
    else cout << (fastPow(2,n+2)+1-3)*fastPow(6,mod-2)%mod << endl;
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