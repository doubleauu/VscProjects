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
url: https://codeforces.com/contest/2200/problem/A
我们发现无论从哪里开始，一轮过后所有人的菜数量都要减一，所以最后剩余的就一定是最大值
也就是要求由多少个最大值；
*/
void solve() {
	int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int t = *max_element(all(a));
    for(int i = 1; i <= n; i++) {
        if(a[i] == t) ans++;  
    }
    cout << ans << endl;
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