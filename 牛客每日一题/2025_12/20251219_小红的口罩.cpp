#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    multiset<ll> st;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        st.insert(t);
    }
    ll ans = 0;
    while(k >= 0) {
        k -= *st.begin();
        ans++;
        st.insert(*st.begin()*2);
        st.erase(st.begin());
    }
    cout << ans-1 << "\n";
}
// 64 位输出请用 printf("%lld")