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
url: https://ac.nowcoder.com/acm/contest/132940/A
对多个个数去重，想到set结构；
但是此题数目较少，直接枚举就行
*/
void solve() {
	int a, b, c, l, r;
    cin >> a >> b >> c >> l >> r;
    int ct = 0; // 统计相等的个数
    if(a>=l && a<=r) {
        ct++;
    }

    if(b!=a) {
        if(b>=l && b<=r) ct++;
    }
    if(c!=b && c!=a) {
        if(c>=l && c<=r) ct++;
    }
    cout << r-l+1-ct << endl;
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