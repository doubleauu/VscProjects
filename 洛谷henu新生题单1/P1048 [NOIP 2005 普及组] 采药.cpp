/**
 * @brief: 贪心？动态规划？状态不连续怎么使用动态规划？
 * @details: 01背包模板问题
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, M;
    cin >> T >> M;
    int *wt = new int[M];
    int *val = new int[M];
    for(int i = 0; i < M; i++) {
        cin >> wt[i] >> val[i];
    }
    
    vector<vector<int>> dp(M+1, vector<int>(T+1,0));
    // int **dp = new int*[M+1];
    // for(int i = 0; i < M+1; i++) {
    //     dp[i] = new int[T+1]();
    // }

    // int *data = new int[(M+1) * (T+1)]();
    // int **dp = new int*[M+1];
    // for(int i = 0; i < M+1; i++) {
    //     dp[i] = data + i*(T+1);
    // }
    
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= T; j++) {
            if(j < wt[i-1]) {
                dp[i][j] = dp[i-1][j];
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    cout << dp[M][T];
    delete[] wt;
    delete[] val;
}