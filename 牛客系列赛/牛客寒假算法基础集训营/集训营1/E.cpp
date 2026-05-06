// Problem: Block Game
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/E
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
 		int n, k;
 		cin >> n >> k;
 		vector<ll> a(n+1), pre(n+1); // 第i个数字与前面一个数字的和；
 		a[0] = k;
 		ll maxn = INT_MIN;
 		for(int i = 1; i <= n; i++) {
 			cin >> a[i];
 			pre[i] = a[i] + a[i-1];
 			maxn = max(maxn,pre[i]);
 		}
 		pre[0] = a[0]+a[n];
 		maxn = max(maxn, pre[0]);
 		cout << maxn << endl;
 	}
}