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
//url:
// 题目要求 L 的下标小于 Q, 考虑最优情况一定是某一点左边全是 L, 右边全是 Q;
// 则记录前缀和，联想天梯赛选拔L1-8，题目相似
// dp, 找转移函数即可；
void solve() {
	int n;
    cin >> n;
    vector<char> a(n+1);
    vector<int> pre(n+1), preL(n+1), preQ(n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        preL[i] += preL[i-1];
        preQ[i] += preQ[i-1];
        pre[i] += pre[i-1];
        if(a[i]=='L') preL[i]++;
        if(a[i]=='Q') {
            preQ[i]++;
            ans += preL[i];
        }
        if(a[i]=='?') {
            pre[i]++;
            ans += preL[i];
        }
        
    }
    vector<ll> dp(n+1);
    dp[1] = ans;
    // cout << ans << endl;
    for(int i = 2; i <= n; i++) {
        
        if(a[i-1]=='?') {
            dp[i] = dp[i-1]+(pre[n]-pre[i-1]+preQ[n]-preQ[i-1])-(pre[i-2]+preL[i-2]);
        }else {
            dp[i] = dp[i-1];
        }
        ans = max(ans,dp[i]);
        // cout << dp[i] << endl;
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