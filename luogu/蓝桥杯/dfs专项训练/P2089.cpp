// Problem: P2089 烤鸡
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2089
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
//因为递归中是按顺序的；所以不用值传递，用一个数组即可
//题目要求先输出方案数，所以要先存储答案后统一输出
//因为我们是顺序操作的，自然是按字典序排序
int n;
vector<int> a(11);
vector<vector<int>> ans;
ll res = 0;
// m 表示剩余配料量
void dfs(int now, int m)
{
    if (now == 11 && m == 0) {
        ans.pb(a);
    }
    if (m < 0)
        return;
    if (now > 10)
        return;
    for (int i = 1; i <= 3; i++) {
        a[now] = i;
        dfs(now + 1, m - i);
    }
}
void solve()
{
    cin >> n;
    if (n < 10) {
        cout << 0 << endl;
        return;
    }
    dfs(1, n);
    cout << ans.size() << endl;
    for (auto a : ans) {
        for (int i = 1; i <= 10; i++) {
        	cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}