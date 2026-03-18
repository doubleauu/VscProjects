// Problem: Branch of Faith
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120563/J
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：
*/
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
const int p = 1e9+7;
const int N = 1e6+5;


int main() {
	vector<ll> a(61), pre(61);
	a[0] = 1;
	pre[0] = 1;
	for(int i = 1; i <= 60; i++) {
		a[i] = 2*a[i-1];
		pre[i] = pre[i-1] + a[i];
		// if(pre[i]>1e18) {
			// cout << i << endl;
			// break;
		// }
	}
 	int t;
 	cin >> t;
 	while(t--) {
 		ll n, q;
 		cin >> n >> q;
 		// 共有 t 层
 		auto t = lower_bound(all(pre),n)-pre.begin()+1;
 		// cout << t << endl;
 		while(q--) {
 			ll x;
 			cin >> x;
 			if(x==1) cout << 1 << endl;
 			else if(x==2||x==3) cout << 2 << endl;
 			else if(x > pre[t-2]) {
 				cout << n-pre[t-2] << endl;
 			}else{
 				// 属于第 tn 层
 				int tn = lower_bound(all(pre),x)-pre.begin()+1;
 				cout << a[tn-1] << endl;
 			}
 		}
 		
 	} 
}