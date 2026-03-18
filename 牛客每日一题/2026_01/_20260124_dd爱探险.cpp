// 状压dp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<vector<ll> > m(n, vector<ll>(n));
    vector<vector<vector<ll>>> dp(1<<n, vector<vector<ll>>(n, vector<ll>(4, 1e9)));

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    for(ll i = 0; i < n; i++) dp[1<<i][i][0] = 0;
    for(ll i = 1; i < (1 << n); i++){
        for(ll j = 0; j < n; j++) {

            if(!(i>>j&1)) continue;
            for(int jj = 0; jj < n; jj++) {
                if(j==jj || !(i>>jj&1)) continue;
                int ii = i ^ (1 << j);
                for(int l = 0; l < 4; l++) {
                    dp[i][j][l] = min(dp[i][j][l],dp[ii][jj][l]+m[jj][j]);
                }
                dp[i][j][1]=min(dp[i][j][1],dp[ii][jj][0]);//重力加速
                dp[i][j][2]=min(dp[i][j][2],dp[ii][jj][0]+m[jj][j]*2);//反重力加速
                dp[i][j][3]=min(dp[i][j][3],dp[ii][jj][1]+m[jj][j]*2);//已经重力加速过了
                dp[i][j][3]=min(dp[i][j][3],dp[ii][jj][2]);//已经反重力加速过了
            }
        }
    }
    ll ans = 1e9;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp[(1<<n)-1][i][3]);
    }
    cout << ans << "\n";
}