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
url: https://codeforces.com/contest/2195/problem/C
观察发现不合格的情况只有两种，且只针对相邻情况；
1. 两个数相加结果为 7
2. 两个数相同
看到数据范围我们想到 O(n) 遍历；
我们如果修改一个元素，其两边的元素是否合格都可能受影响，因为一共有 6 种选择
收到两边元素最多两个限制，所以我们一定能进行一次修改让左右两边的元素变为合格（我们不需要具体找到这个元素）
所以我们 ans++ 后将不用对下一个元素进行检查，则 i++;
*/
void solve() {
	int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i]==a[i-1] || a[i]+a[i-1]==7) ans++, i++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}