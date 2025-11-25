#include <bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
int ans = -2e9; // 用一个稍微大一点的负数，防止 INT_MIN 加法溢出

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    
    // 初始化 DP 数组
    for(int i = 0; i <= N; i++) b[i] = -2e9;
    
    // 读入
    for(int i = 0; i <= N; i++) cin >> a[i];

    // 假设从 0 出发
    b[0] = a[0];

    for(int i = 1; i <= N; i++) {
        // 遍历所有能跳到 i 的前驱节点 j
        // j 的范围是 [i-R, i-L]
        for(int j = i - L; j >= i - R; j--) {
            if(j < 0) break; // 越界保护
            if(b[j] == -2e9) continue; // 不可达点跳过
            b[i] = max(b[i], b[j] + a[i]);
        }
    }

    // 统计答案：题目通常问跳到 N 或者是 N 之后的区间？
    // 假设是跳到 [N-R+1, N] 任意位置算结束，或者必须跳到 N
    // 这里保留你的逻辑
    for(int i = max(0, N - R + 1); i <= N; i++) {
        ans = max(ans, b[i]);
    }
    
    cout << ans;
}