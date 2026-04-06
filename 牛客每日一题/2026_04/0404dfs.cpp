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

bool comp(vector<int> a, vector<int> b) {
	return a.size() > b.size();
}
void solve() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> path(n+1);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		path[u].pb(v);
		path[v].pb(u);
	}
	vector<vector<int>> ans;
	vector<int> v(n+1); // 标记
	vector<int> t;  // 存储临时答案
	auto dfs = [&](auto&& self, int now, int type) -> void {
		for(auto i : path[now]) {
			if(v[i]) continue;
			if(a[i]!=type) continue;
			v[i] = 1;
			t.pb(i);
			self(self,i,type);
		}
	};
	
	for(int  i = 1; i <= n; i++) {
		if(!v[i]) {
			v[i] = 1;
			t.resize(0);
			t.pb(i);
			dfs(dfs,i,a[i]);
			ans.pb(t);
		}
	}
	sort(all(ans),comp);
	int sz = ans[0].size();
	int sum = 0;
	vector<int> res(n+1);
	for(auto t : ans) {
		if(t.size() < sz) break;
		sum += sz;
		for(auto i : t) res[i] = 1;
	}
	cout << sum << endl;
	for(int i = 1; i <= n; i++) {
		if(res[i] == 1) cout << i << " ";
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