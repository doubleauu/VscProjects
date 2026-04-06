// Problem: P1118 [USACO06FEB] Backward Digit Sums G/S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1118
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
const int mod = 1e9+7;
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
void solve() {
	int n, tar;
	cin >> n >> tar;
	vector<vector<int>> a(n+1,vector<int>(n+1));
	for(int i = 1; i <= n; i++) {
		a[i][1] = a[i][i] = 1;
		for(int j = 2; j <= i-1; j++) {
			a[i][j] = a[i-1][j-1]+a[i-1][j];
		}
	}
	vector<int> w(n+1);
	for(int i = 1; i <= n; i++) w[i] = a[n][i];
	vector<int> ans(n+1), v(n+1);
	
	bool found = 0;  // dfs有多个分支，应设置一个变量及时退出；
	// 寻找第 pos 位置
	auto dfs = [&](auto&& self, int pos, int sum) -> void{
		if(pos > n && sum == tar) {found=1; return;}  // 只有当找到n位且和为tar才能退出
		if(found) return;
		if(pos>n) return;
		if(sum > tar) return;
		for(int i = 1; i <= n; i++) {
			if(v[i]) continue;
			v[i] = 1;
			ans[pos] = i;
			self(self,pos+1,sum+w[pos]*i);
			if(found) return;  // found主要用于此处；
			v[i] = 0;  // pos处为 i 不可行，就要进入下一个循环，需要清除限制
			
		}
	};
	dfs(dfs,1,0);
	if(!found) return;
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
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