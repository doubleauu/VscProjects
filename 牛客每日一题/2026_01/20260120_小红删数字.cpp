//动态规划，主要点是找准状态转移方程，这一题就是后一个数结尾的多种情况到前一个数字结尾情况数量的转移；
// 注意第一次操作要单独处理（也就是最后两个数）， 因为第一次操作中最后一个数可能很大，超过了我们规定的 0-9 范围，后面的操作都会对 10 取模就可以直接处理了；
// 因为我们有一次特殊处理，所以要注意 n=1 时的边界处理；
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int p = 1e9+7;

const int maxn = 2e5 + 10;

int ans[maxn][10];  // i, j 表示第 i 个数字为 0-9 的方案数量
int a[maxn];  // 数组太大，放到栈中定义会溢出；

int main() {
    int n;
    cin >> n;
    if(n == 1) {  // 一般有一个点错就是卡边界了；
        int t;
        cin >> t;
        for(int i = 0; i < 10; i++) {
            if(i == t) cout << 1 << " ";
            else cout << 0 << " ";
        }
        return 0;
    }
    // vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // ans[n][a[n]] = 1;
    ans[n-1][((a[n]%10)+(a[n-1]%10)) % 10] = 1;
    ans[n-1][((a[n]%10)*(a[n-1]%10)) % 10] = 1;
    // cout << ans[n-1][2] << " " << ans[n-1][7] << endl;
    for(int i = n-2; i >= 1; i--) {
        int x = a[i];
        for(int j = 0; j < 10; j++) {
            if(ans[i+1][j] > 0) {
                
                int y = j;
                int t1 = ((x%10)+(y%10)) % 10, t2 = ((x%10)*(y%10)) % 10;
                
                ans[i][t1] = (1LL*ans[i][t1] + ans[i+1][j])%p;
                ans[i][t2] = (1LL*ans[i][t2] + ans[i+1][j])%p;

            }
            else continue;
        }
    }

    for(int i = 0; i < 10; i++) {
        cout << ans[1][i] << " ";
    }
}