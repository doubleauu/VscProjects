/**
 * @brief: 每种药草可以无限采摘
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T, M;
    cin >> T >> M;
    vector<int> wt(M);
    vector<int> val(M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &wt[i], &val[i]);
    }
    vector<ll> dp(T+1); //使用一维数组表示背包容量

    // //从后往前遍历，保证仅放一次
    // for(int i = 1; i <= M; i++) {
    //     for(int j = T; j >= wt[i-1]; j--) {
    //         dp[j] = max(dp[j], dp[j-wt[i-1]] + val[i-1]);
    //     }
    // }

    //从前向后遍历，表示可以多次放入
    for(int i = 1; i <= M; i++) {
        for(int j = wt[i-1]; j <= T; j++) {
            dp[j] = max(dp[j-wt[i-1]]+val[i-1], dp[j]);  //从前往后遍历，前面的结果会影响后面，导致多次放入
        }
    }
    cout << dp[T];
}


#if 0
int main() {
    int T, M;
    cin >> T >> M;
    vector<int> wt(M);
    vector<int> val(M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &wt[i], &val[i]);
    }
    vector<vector<ll>> dp(M+1, vector<ll>(T+1));
    for(int i = 1; i <= M; i++) {
        for(int j = 0; j <= T; j++) {
            if(j < wt[i-1]) {
                dp[i][j] = dp[i-1][j];
            }else {
                dp[i][j] = max(dp[i][j-wt[i-1]]+val[i-1],max(dp[i-1][j-wt[i-1]]+val[i-1], dp[i-1][j]));//背包没有满就可以继续采摘
            }
        }
    }
    cout << dp[M][T];
}
#endif