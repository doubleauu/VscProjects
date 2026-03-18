//找最长递增子序列，动态规划思想：dp[i]:以当前位置为结尾的最长递增子序列长度
// dp[i]是从前面的dp[j]转移而来：dp[i] = max(dp[i], dp[j]+1); // 找到多个转移状态中最大的结果
#include <bits/stdc++.h>
using namespace std;

struct M {
    int h;
    int a;
};

bool comp(M m1, M m2) {
    if(m1.h != m2.h) return m1.h <= m2.h;
    else return m1.a <= m2.a;
}

int main() {
    int n, H, A;
    cin >> n >> H >> A;
    vector<M> arr(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].h;
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].a;
    }
    sort(arr.begin(), arr.end(), comp);
    
    vector<int> dp(n+1);
    for(int i = 1; i <= n; i++) {
        if(arr[i].a >= A || arr[i].h >= H) dp[i] = -1;
        else dp[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(dp[i] == -1) continue;
        for(int j = 1; j < i; j++) {
            if(arr[j].a < arr[i].a && arr[j].h < arr[i].h) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans;
    
}