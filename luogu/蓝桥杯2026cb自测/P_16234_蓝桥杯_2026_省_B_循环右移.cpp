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
//url:https://www.luogu.com.cn/problem/P16234?contestId=320659
// 观察循环后移的操作，发现数组中所有数都相等，所以直接看x-y有几个数即可；
void solve() {
	ll n, x, y;
    cin >> n >> x >> y;
    if(y < x) {
        cout << 0 << endl;
        return;
    }
    cout << y-x+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}