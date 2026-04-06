// Problem: O. The Martian
// Contest: Codeforces - UDESC Selection Contest 2025-1
// URL: https://codeforces.com/gym/105950/problem/O
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
// #define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> path(n+1);
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		// emplace_back 函数，原地构造对象；
		path[u].emplace_back(v,w);
		path[v].emplace_back(u,w);
	}
	vector<int> dis(n+1,1e9);
	dis[1] = 0;
	// pair 支持字典序比较，先比较first, 再比较second；
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1});
	
	// 此时pair中 第一个是权值，第二个是位置
	while(!pq.empty()) {
		auto [d,u] = pq.top(); pq.pop();
		if(dis[u] == d) {
			for(auto &[v,w] : path[u]) {
				// 此处为什么可以更新，因为每次取出来的都是最小的吗？
				// max(w,d) 取得的当前路径上最大权值， dis[v] 记录已经得到所有路径最大权值的最小值；
				if(max(w,d) < dis[v]) {
					dis[v] = max(w,d);
					pq.push({dis[v],v});
				}
			}
		}
	}
	
	int d;
	cin >> d;
	vector<int> v1(d+1), v2(d+1);
	for(int i = 1; i <= d; i++) cin >> v1[i], v1[i] = dis[v1[i]];
	for(int i = 1; i <= d; i++) cin >> v2[i];
	
	sort(v1.begin()+1,v1.end(),greater<int>()); // 每一天是独立的，排序不影响；
	sort(v2.begin()+1,v2.end()); // 方便每次取满足条件的最短的梯子；
	
	int ans = 0;
	for(int i = 1; i <= d; i++) {
		if(v1[i] <= v2.back()) {
			ans++;
			v2.pop_back();
		}
	}
	cout << ans << endl;
	
	
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