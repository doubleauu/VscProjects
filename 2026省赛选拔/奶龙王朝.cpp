#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n+1), b(m+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());

    // ll res = 0;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         res += min(a[i]+b[j],p);
    //     }
    // }
    // cout << res << endl;

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int t = p-a[i];
        if(t<0) {
            // ans += m*p;
            continue;
        }
        int ct = upper_bound(b.begin()+1,b.end(),t)-b.begin()-1;
        // cerr << i << " " << ct << endl;
        ans += ct*a[i];
    }
    for(int i = 1; i <= m; i++) {
        int t = p-b[i];
        if(t<0) {
            ans += n*p;
            continue;
        }
        int ct = upper_bound(a.begin()+1,a.end(),t)-a.begin()-1;
        ans += ct*b[i] + (n-ct)*p;
        // cerr << i << " " << ct << endl;
    }
    cout << ans << endl;
}


int main() {
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}