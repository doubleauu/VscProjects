// Problem: Card Game
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/B
// Memory Limit: 512 MB
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
const int p = 998244353;
const int N = 2e5+5;

ll pre[N];

void f() {
	pre[0] = 1;
	for(int i = 1; i <= N; i++) {
		pre[i] = i*pre[i-1]%p;
	}
}

int main() {
	f();
 	int t;
 	cin >> t;
 	while(t--) {
 		int n;
 		cin >> n;
 		vector<int> a(n+1),b(n+1);
 		bool b1 = false;
 		int maxa = INT_MIN, maxb = INT_MIN;
 		int mina = INT_MAX, minb = INT_MAX;
 		for(int i = 1; i <= n; i++) {
 			cin >> a[i];
 			mina = min(mina,a[i]);
 			maxa = max(maxa,a[i]);
 		}
 		for(int i = 1; i <= n; i++) {
 			cin >> b[i];
 			maxb = max(b[i],maxb);
 			minb = min(b[i],minb);
 			if(b[i] == 1) b1 = true;
 		}
 		// if(b1 || maxa < minb) {
 			// cout << pre[n] << endl;
 			// // return 0;
 		// }
 		ll cnt = 0;
 		for(int i = 1; i <= n; i++) {
 			if(a[i] > minb) cnt++;
 		}
 		cout << pre[cnt]*pre[n-cnt]%p << endl;
 	}   
}