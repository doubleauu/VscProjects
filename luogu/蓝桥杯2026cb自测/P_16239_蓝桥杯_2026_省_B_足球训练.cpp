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
//url:
// 

ll fast(ll a, ll b){
    ll ans = 1;
    ll base = a;
    while(b) {
        if(b&1) ans = ans*base%mod;
        base = base*base%mod;
        b >>= 1;
    }
    return ans;
}
ll inv(ll n) {
    return fast(n,mod-2);
}

void solve() {
	int n, m;
    cin >> n >> m;
    vector<ll> a(n+1), b(n+1);
    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        ans = ans*a[i]%mod;
    }

    function<void(int,int,ll)> dfs = [&](int now, int ct, ll res) {
        if(ct==0) {
            ans = max(ans,res);
            return;
        }
        if(now > n) return;
        
        for(int i = 0; i <= ct; i++) {
            dfs(now+1,ct-i,res*inv(a[now])%mod*(a[now]+b[now]*i)%mod);
        }
    };
    dfs(1,m,ans);
    cout << ans << endl;
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