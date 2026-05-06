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
//url:https://www.luogu.com.cn/problem/P16235?contestId=320659
// 我们先找处队伍数量为 n, 不是 5 的倍数直接 F
// 所有类型的队员数量都不能超过 n, 否则 F
void solve() {
	int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % 5 != 0) {
        cout << "F" << endl;
        return;
    }
    ll res = sum/5;
    for(int i = 1; i <= n; i++) {
        if(a[i] > res) {
            cout << "F" << endl;
            return;
        }
    }
    cout << "T" << endl;
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