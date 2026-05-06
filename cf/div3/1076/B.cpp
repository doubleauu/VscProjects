// Problem: B. Reverse a Permutation
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
		int n;
		cin >> n;
		vector<int> a(n+1);
		vector<int> b(n+1);
		int pos1 = 0, pos2 = 0, t = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			b[i] = n-i+1;
		}
		
		
		for(int i = 1; i <= n; i++) {
			if(a[i] != b[i]) {
				pos1 = i;
				t = b[i];
				break;
			}
		}
		for(int i = 1; i <= n; i++) {
			if(a[i] == t) {
				pos2 = i;
			}
		}
		// cout << pos1 << " " << pos2 << endl;
		if(pos1) reverse(a.begin()+pos1, a.begin()+pos2+1); // reverse函数为左闭右开；
		for(int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		
	}
}