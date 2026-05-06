// 模板前缀和；用于降低多次区间查询的复杂度;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);  // 输入次数很多，注意开启优化，取消同步流
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    vector<ll> pre(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + 1LL*a[i];  //提前转为ll类型防止溢出；
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << "\n";
    }
}