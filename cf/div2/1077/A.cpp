// Problem: A. Divisible Permutation
// Contest: Codeforces - Codeforces Round 1077 (Div. 2)
// URL: https://codeforces.com/contest/2188/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

const int N = 105;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(105);
		// for(int i = 1; i <= n; i++) a[i] = 1;
		// deque<int> dq;
		// dq.pb(1);
		// for(int i = 2; i <= n; i++) {
			// if((i-1)+a[i]) 
		// }
		vector<int> ans(n+1);
		for(int i = 1; i <= n; i++) {
			// fill(a.begin()+1,a.begin()+n+1,1);
			for(int k = 1; k <= n; k++) a[k] = 1;
			ans[1] = i;
			a[i]++;
			// bool b = false;
			for(int j = 2; j <= n; j++) {
				int t1 = ans[j-1]+j-1;
				int t2 = ans[j-1]-(j-1);
				if(a[t1]==1 && a[t2]==1) {
					a[min(t1,t2)]++;
					ans[j] = min(t1,t2);
					continue;
				}
				if(a[t1]==1 && a[t2]!=1) {
					a[t1]++;
					ans[j] = t1;
					continue;
				}
				if(a[t1]!=1 && a[t2]==1) {
					a[t2]++;
					ans[j] = t2;
					continue;
				}
				if(a[t1]!=1 && a[t2]!=1) {
					// b = true;
					break;
				}
			}
			if(ans[n] != 0) break;
		}
		// if(ans[n] == 0) {
// 			
		// }
		for(int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	
}