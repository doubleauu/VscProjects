// 查找最小输入次数；使相邻数字间距的最大值刚好为k，则有两种情况：
/*
 * 1. 当前最大间距大于k，就要在间距大的地方插入，因为要尽量少，所以每次插入都使得与当前较小的数间距刚好为k,
 * 2. 特殊情况：当前最大间距小于k，只需要在任意位置插入一个数使得一边间距恰好为 k ,一边间距小于 k 即可；
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1), diff(n+1);  //提前写差分数组更方便；

    bool nok = true;  // 最大间距小于k,就在任意位置插入一个数使与相邻一个数字间距满足k即可；

    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = abs(a[i] - a[i-1]);
        if(i > 1 && diff[i] >= k) nok = false;  // 注意检查条件要从 i>1 开始（不能添加到第一项之前）
    }

    ll ans = 0;
    for(ll i = 2; i <= n; i++) {
        if(diff[i] > k) {

            ans += (diff[i] - 1) / k;  // 简化判断当前除法结果是否为整数引发的两种情况；

            // if(diff[i] % k == 0) {   // 复杂版本：(double)diff[i]/k == diff[i]/k
            //     ans += diff[i]/k-1;
            // }
            // else ans += diff[i]/k;
        }
    }
    if(nok && ans == 0) cout << 1;  // 特殊情况判断；
    else cout << ans;
}