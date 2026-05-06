// Problem: B3622 枚举子集（递归实现指数型枚举）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3622
// Memory Limit: 128 MB
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
// 通过递归函数传副本实现各个递归的参数数组分离
int n;
vector<vector<char>> ans;
// 派出 m 个人, 
// int res = 0;
void dfs(int now, int tar, int ct, vector<char> a) {
	// for(char i : a) {
		// cerr << i;
	// }
	// if(ct==tar) res++;
	if(now > n+1) return;
	if(ct==tar) {
		ans.pb(a);
		return;
	}
	// 分两种情况，此处选和不选；
	dfs(now+1,tar,ct,a);
	a[now] = 'Y';
	dfs(now+1,tar,ct+1,a);
}
bool comp(vector<char> a, vector<char> b) {
	for(int i = 1; i <= n; i++) {
		if(a[i] < b[i]) return 1;
		if(a[i] > b[i]) return false;
	}
	return 1;
}
void solve() {
	cin >> n;
	vector<char> a(n+1,'N');
	for(int i = 0; i <= n; i++) {
		dfs(1,i,0,a);
	}
	// cout << res << endl;
	sort(ans.begin(),ans.end(),comp);
	for(auto i : ans) {
		for(int j = 1; j <= n; j++) {
			cout << i[j];
		}
		cout << endl;
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