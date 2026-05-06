#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    ll a, b, n;
    cin >> a >> b >> n;
    // ll res = 0;
    // ll ra = 0, rb = 0, rc = 0;
    // for(int i = 1; i <= n; i++) {
    //     if(i%a==0 || i%b==0) res++;
    //     if(i%a==0) ra++;
    //     if(i%b==0) rb++;
    //     if(i%a==0 && i%b==0) rc++;
    // }
    // cout << res << endl;
    // cout << ra << " " << rb << " " << rc << endl;
    // cout << n/a+n/b-n/a/b << endl;
    cout << n/a+n/b-n/lcm(a,b) << endl;
}


int main() {
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}