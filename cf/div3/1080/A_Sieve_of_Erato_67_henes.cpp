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
url: https://codeforces.com/contest/2195/problem/A
两两配对问题，固定一个，另一个二分查找；
正解：发现67是一个质数，所以答案就是找数组中有无67即可；
*/
void solve() {
	int n;
    cin >> n;
    vector<double> a(n+1,1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    for(int i = 1; i <= n; i++) {
        if(binary_search(all(a),67/a[i])) {
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
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