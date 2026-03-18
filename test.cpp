// 两个空间站相互跳跃代价不相等，应该尽量选择代价小的方法，但我们又不能确定能一直以最小代价路径前进；要使用动态规划吗？
// 每个空间站经历一次，可以使用一个标记数组；
// 我们也不知道如何选择起点，或者可以跳一个环形，然后减去最大的一步？
// 重力加速应该选择代价最大的一次，相反，反重力加速应该选择跳跃代价最大的；我们不需要特别规划，可以再跳跃结束后再进行计算，记录跳跃过程中的两个极值；

// 难道是最优路径问题？使用 bfs ? 可是一个空间站就有十五种方案；感觉还是动态规划：以。。。为结尾的路径代价；
#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > a(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> v(n+1); // 标记数组；

    // 尝试从第一个空间站出发，
    // ll ans = 0;
    int maxn = INT_MIN, minn = INT_MAX;
    vector<vector<ll> > ans(n+1, vector<ll>(n+1));
    // n 的值最大只有 16，或许可以选择更暴力的写法；
    for(int i = 1; i <= n; i++) {
        if(i == n) {
            break;
        }
        for(int j = i+1; j <= n; j++) {
            ans[i][j] += a[i][j];
        }
    }

    vector<vector<ll> > visit(n+1, vector<ll>(n+1));  // 第 i 步的 第 j 种情况；
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            
        }
    }

}