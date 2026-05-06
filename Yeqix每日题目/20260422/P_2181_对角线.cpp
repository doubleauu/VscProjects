#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
/*
url: https://www.luogu.com.cn/problem/P2181
题目没有对多边形进行限制，所以我们可以任意画图找规律
每条对角线消耗两个点，然后将多边形分为两部分，两边各个顶点相连一定有交点
所以只需要求两边顶点个数 a*b 即可；
1e5 的数据范围直接遍历即可；
注意：组合数学题目很容易爆 ll，注意处理
*/
void solve() {
	int n;
    cin >> n;
    if(n<=3) {
        cout << 0;
        return;
    }
    int ct = n-3; // 对角线数量；
    ll ans = 0;
    // 先固定求一个点能构造的交点数量，此处也要开 ll
    for(ll i = 1; i <= ct; i++) {
        ans += i*(n-2-i);
    }
    // 乘以 n 得到 n 个点的结果
    // 但是对于每条分割线我们都算了两次，每个交点也算了两次（由两条线构成）；
    // 先除再乘防止溢出,但是ans不一定是 4 的倍数，我们将两个除法分开写，否则会wa
    // 右上边的循环可知，乘法两边一定有一个偶数，所以ans一定是 2 的倍数；
    cout << ans/2*n/2;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed;
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}