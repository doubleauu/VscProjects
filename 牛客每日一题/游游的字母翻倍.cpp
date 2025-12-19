#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<char> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> ct(n+1,1);

    vector<int> pre(n+1);

    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1]+ct[i];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        auto x = lower_bound(pre.begin(),pre.end(),l);
        auto y = lower_bound(pre.begin(),pre.end(),r);
        int t1 = *x - l;
        ct[x-pre.begin()] += t1+1;
        int t2 = *y -r;
        ct[y-pre.begin()] *= 2;
        ct[y-pre.begin()] -= t2;

        for(auto i = x+1; i < y; i++) {
            ct[i-pre.begin()] *= 2;
        }
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i-1]+ct[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < ct[i]; j++) {
            cout << a[i];
        }
    }
}