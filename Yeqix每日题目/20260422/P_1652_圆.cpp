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
url: https://www.luogu.com.cn/problem/P1652
简单的几何题目，圆的数量也不大
直接 O(n) 遍历即可
思路：想要最小的穿过数量，我们就要尽量避免，因为可以画曲线，所以如果点在圆外，就一定能避免穿过此园
但是我们的目的是两个点相连，还要考虑另一个点的情况
画图发现分类讨论即可；lambda函数可以减少传参，更方便；
*/
void solve() {
    int n;
    cin >> n;
    vector<int> x(n+1), y(n+1), r(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 返回是否在圆内
    auto f = [=](int op, int i) {
        int a = x[i], b = y[i], c = r[i];
        double d;
        if(op == 1) {
            d = sqrtl((a-x1)*(a-x1)+(b-y1)*(b-y1));
        }else {
            d = sqrtl((a-x2)*(a-x2)+(b-y2)*(b-y2));
        }
        if(d < c) return true;
        return false;
    };
	int res = 0;
    // 分别判断每个圈是否会穿过；
    for(int i = 1; i <= n; i++) {
        if(f(1,i)) {
            if(!f(2,i)) res++;
        }else {
            if(f(2,i)) res++;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}