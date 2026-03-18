// Problem: NCPC
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/B
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：只要有比 i 大的选手存在就不可能赢
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;


int main() {
 	int t;
 	cin >> t;
 	while(t--) {
 		int n;
 		cin >> n;
 		vector<int> a(n+1);
 		int maxn = INT_MIN;
 		for(int i = 1; i <= n; i++) {
 			cin >> a[i];
 			maxn = max(maxn,a[i]);
 		}
 		vector<int> b(a);
 		sort(b.begin()+1,b.end());
 		deque<int> dq;
 		function<void(int)> dfs = [&](int tmax) {  // 传入当前的最大值
 			if(tmax == 0) return;
 			for(int i = 1; i <= n; i++) {
	 			if(a[i] == tmax) {
	 				dq.pb(i);
	 			}
 			}
 			// else return;
 		};
 		dfs(maxn);
 		string ans ="";
 		if(dq.size()%2 != 0) {
	 		ans.append(n+1,'0');  // 实现下标从 1 开始；
			while(!dq.empty()) {
				int x = dq.front();
				dq.pop_front();
				ans[x] = '1';
			}
		}else {
	 		ans.append(n+1,'1');  // 实现下标从 1 开始；
			while(!dq.empty()) {
				int x = dq.front();
				dq.pop_front();
				ans[x] = '0';
			}
		}
 		
 		ans.erase(0,1);
 		cout << ans << endl;
 	}   
}