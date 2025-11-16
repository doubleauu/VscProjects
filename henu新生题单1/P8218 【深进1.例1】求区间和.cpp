/**
 * @brief: 求指定区间和,使用前缀和数组减低复杂度
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getSum(int a, int b, vector<int> nums) {
    int ans = 0;
    for(int i = a; i <= b; i++){
        ans += nums[i];
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n+1);
    vector<int> preSum(n+1);   //使用前缀和数组，将多次查询区间和的复杂度从o(n)降为o(1)
    for(int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        preSum[i] = preSum[i-1] + nums[i];
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        // printf("%d\n",getSum(a,b,nums));
        printf("%d\n",preSum[b] - preSum[a-1]);
    }
    return 0;
}