#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void so() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        map<int,int> mp;
        ans++;
        mp[i]++;
        int mi = 1;
        int ma = 1;
        for(int j = i+1; j <= n; j++) {
            mp[a[j]]++;
            ma = max(ma,mp[a[j]]);
            mi = min(mi,mp[a[j]]);
            if(ma==mi) ans++;
        }
    }
    cout << ans << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        map<int,int> mp;
        for(int j = i; j <= n; j++) {
            mp[a[j]]++;
            int t = mp[a[j]];
            bool b = 0;
            for(auto k : mp) {
                if(k.second!=t) {
                    b = 1;
                    break;
                }
            }
            if(!b) ans++;
        }
    }
    cout << ans << endl;
}


int main() {
    int T = 1;
    // cin >> T;
    while(T--) {
        // solve();
        so();
    }
}