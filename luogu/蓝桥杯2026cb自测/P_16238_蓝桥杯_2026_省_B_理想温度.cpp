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
//url:https://www.luogu.com.cn/problem/P16238?contestId=320659
// 
void solve() {
	int n;
    cin >> n;
    map<int,int> mp;
    vector<ll> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        mp[b[i]-a[i]]++;
    }
    int ans = 0;
    for(auto p : mp) {
        ans = max(ans,p.second);
    }
    cout << ans << endl;
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