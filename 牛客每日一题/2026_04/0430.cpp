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
url: https://www.nowcoder.com/practice/d483ab6bf19245518730a75c6ea108ae?channelPut=tracker2
求区域内元素数量，我们可以先对数组进行排序
就转化为了求区间长度；
只需要找到 l 和 r 的位置即可，其之间元素个数等于 $ r-l+1 $；
可使用标准库二分函数，注意处理找不到返回 end() 的情况；
*/ 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l > r) {
            cout << 0 << endl;
            continue;
        }
        auto tl = lower_bound(a.begin()+1,a.end(),l);
        if(tl==a.end()) {
            cout << 0 << endl;
        }else {
            auto tr = upper_bound(a.begin()+1,a.end(),r);
            if(tr==a.end()) cout << n-(tl-a.begin())+1 << endl;
            else cout << tr-tl-1+1 << endl;
        }
    }
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