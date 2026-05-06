// Problem: P13886 [蓝桥杯 2023 省 Python A] 分糖果
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P13886
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
const int mod = 1e9+7;
const int N = 1e6+5;
// 
// int n = 9, m=16;
ll res = 0;
// 对第 now 个小朋友进行分配
// 然后依次列出之后的情况即可；
void dfs(int n, int m, int now) {
	if(n<0 || m<0) return;
	if(now > 7 && n==0 && m==0) {
		res++;
		return;
	}
	if(now>7) return;
	dfs(n,m-2,now+1);
	dfs(n,m-3,now+1);
	dfs(n,m-4,now+1);
	dfs(n,m-5,now+1);
	dfs(n-1,m-1,now+1);
	dfs(n-1,m-2,now+1);
	dfs(n-1,m-3,now+1);
	dfs(n-1,m-4,now+1);
	dfs(n-2,m,now+1);
	dfs(n-2,m-1,now+1);
	dfs(n-2,m-2,now+1);
	dfs(n-2,m-3,now+1);
	dfs(n-3,m,now+1);
	dfs(n-3,m-1,now+1);
	dfs(n-3,m-2,now+1);
	dfs(n-4,m,now+1);
	dfs(n-4,m-1,now+1);
	dfs(n-5,m,now+1);
}
void solve() {
	dfs(9,16,1);
	cout << res << endl;
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