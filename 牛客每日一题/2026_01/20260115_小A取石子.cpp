//小a要赢，则最后一次拿的时候应该只剩一堆石子；因为b也会使用最优策略，则唯一一种情况就是b拿的时候也只剩2堆均为1的石子；
//不可以不取，就是说每次至少取1个，那么一堆数目为n的石子可以用n次；

//复杂情况是否先取k没什么用了，因为经过一轮ab的拿取也能实现提前拿取k个石子的效果，除非 k=1 && a[i]=1;
//从不能必胜的情况着手：
/*
 * 1. 
 */

// 想了好多情况感觉太复杂，看题解发现是模板题
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    bool has = false;
    int maxn = INT_MIN;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ans ^= a[i];
        if(a[i] == k) has = a[i];
        maxn = max(maxn, a[i]);
    }
    if(ans) return 1;  //不用提前取
    else {  //尝试提前取；
        if(maxn < k) return false;
        else {
            if(has) {
                ans ^= has; //就是把这个数去掉；
                if(ans) return 1;
            }
            ans ^= maxn;
            ans ^= maxn-k;
            if(ans) return 1;
        }
    }
    return false;

}

int main() {
    if(solve()) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}