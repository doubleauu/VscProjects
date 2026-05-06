// Problem: A. DBMB and the Array
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//@brief:
//@details:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, s, x;
		cin >> n >> s >> x;
		vector<int> a(n+1);
		ll sum = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		
		if(sum == s) {
			cout << "YES" << endl;
			continue;
		}
		if(s > sum && (s-sum)%x == 0) cout << "YES" << endl;
		else cout << "NO" << endl; 
	}
}