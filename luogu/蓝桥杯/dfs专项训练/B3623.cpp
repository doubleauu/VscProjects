// Problem: B3623 枚举排列（递归实现排列型枚举）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3623
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
// 
int n, k;
// 依次填写每个位置即可；
// 使用v数组标记，传值函数实现各个递归分离
// pos: 当前位置坐标， val:上一个位置的值
void dfs(vector<int> v, vector<int> a, int pos) {
	v[a[pos-1]] = 1;
	if(pos>k) {
		for(int i = 1; i <= k; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(v[i]) continue;
		// v[i] = 1;   // 写在此处会导致在后续循环中继承，应该进入下一层再标记；
		a[pos] = i;
		dfs(v,a,pos+1);
	}
}
void solve() {
	cin >> n >> k;
	vector<int> a(k+1), v(n+1);
	dfs(v,a,1);
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