// Problem: P2404 自然数的拆分问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2404
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
// 数据范围小，我们直接枚举所有组合，然后去重即可
// 当然还有一种更简单的方法，实现搜索的过程中去重：
// dfs(rest, last)表示：还剩 rest 下一次只能选 >= last 的数
vector<vector<int>> ans;
int n;
void dfs(vector<int> a, int m, int val) {
	a.pb(val);  // 防止写在循环中影响后续；
	if(m==0) {
		ans.pb(a);
		return;
	}
	if(m < 0) return;
	for(int i = 1; i < n; i++) {
		dfs(a,m-i,i);
	}
}
void print(vector<int> a) {
	for(int i = 1; i < a.size()-1; i++) {
		cout << a[i] << "+";
	}
	cout << a.back() << endl;
}
void solve() {
	cin >> n;
	vector<int> a;
	dfs(a,n,0);
	for(auto& i : ans) {  // 此处需要传引用！！！
		sort(all(i));
	}
	sort(all(ans));
	ans.erase(unique(all(ans)),ans.end());
	for(auto a : ans) {
		print(a);
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