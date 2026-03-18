// Problem: 终于再见
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/J
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：
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
 	int n, m;
 	cin >> n >> m;
 	vector<vector<int>> a(n+1);
 	while(m--) {
 		int t1, t2;
 		cin >> t1 >> t2;
 		a[t1].pb(t2);
 		a[t2].pb(t1);
 	}
 	vector<int> b(n+1);
 	for(int i = 1; i <= n; i++) {
 		b[i] = a[i].size();
 	}
 	// 离散化：
 	vector<int> t(b);
 	sort(t.begin(),t.end());
 	unique(t.begin()+1,t.end());
 	for(int i = 1; i <= n; i++) {
 		b[i] = lower_bound(t.begin()+1,t.end(),b[i]) - t.begin();
 		// cout << b[i] << endl;
 	}
 	
 	vector<int> ans(n+1);
 	for(int i = 1; i <= n; i++) {
 		deque<int> dq;
 		set<int> st; //用来存走过的路；
 		st.insert(i);
 		
 		for(auto j : a[i]) {
 			if(st.find(j)==st.end()){
 				dq.pb(j);
 				st.insert(j);
 				if(b[j] > b[i]) {
	 				ans[i] = 1;
	 				break;
	 			}
 			}
 			// dq.pb(j);
 			// if(b[j] > b[i]) {
 				// ans[i] = 1;
 				// break;
 			// }
 		}
 		if(ans[i]) continue;
 		else {
 			int tans = 1;
 			while(!dq.empty()) {
 				int t = dq.size();
 				tans++;  // 向外走一步
 				while(t--) {
 					for(auto j : a[dq.front()]) {
 						if(st.find(j)==st.end()){
			 				dq.pb(j);
			 				st.insert(j);
			 				if(b[j] > b[i]) {
				 				ans[i] = tans;
				 				break;
				 			}
			 			}
 					}
 					if(ans[i]) break;
 					dq.pop_front();
 				}
 				if(ans[i]) break;
 			}
 		}
 	}
 	for(int i = 1; i <= n; i++) {
 		if(ans[i]) cout << ans[i] << " ";
 		else cout << -1 << " ";
 	}
}