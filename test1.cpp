#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<i64> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    i64 ans = INT_MIN;
    vector<i64> dp(n+1);
    for(int i = 1; i <= n; i++) {
        // if((a[i]>0 && dp[i-1]>0)||(a[i]<0 && dp[i-1]<0)) {
        if(abs(dp[i-1]+a[i]) >= abs(a[i])) {
            dp[i] = dp[i-1]+a[i];
        }else {
            dp[i] = a[i];
        }
        ans = max(ans, abs(dp[i]));
    }
    cout << ans;
}