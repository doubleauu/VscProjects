// Problem: Array Covering
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/C
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
		int n;
	 	cin >> n;
	 	vector<int> a(n+1);
	 	int maxn = INT_MIN;
	 	for(int i = 1; i <= n; i++) {
	 		cin >> a[i];
	 		maxn = max(maxn,a[i]);
	 	}   
	 	cout << 1LL*(n-2)*maxn+a[1]+a[n] << endl;
	}
}