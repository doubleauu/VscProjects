#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll  t;
    cin >> t;
    while(t--) {
        ll l, r;
        cin >> l >> r;
        ll n = r-l+1;
        ll ct = (l+r)*(r-l+1)/2;

        int m;
        cin >> m;
        while(m--) {
            int y;
            cin >> y;
            cout << (ct%y == 0 ? 0: 1) << endl;
        }
    }
}