// Problem: 小红的奶油蛋糕工坊
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127240/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//@brief:
//@details:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	if(n == 3) {
		for(int i = 1; i <= 3; i++) {
			int t;
			cin >> t;
			if(t == 2) cout << 1 << " ";
			else cout << t << " ";
		}
		return 0;
		
	}
	int ct = ceil(n/2.0);
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(ct % 2 == 0) {
			if(a[i] >= n/2 - ct/2 && a[i] < n/2 + ct/2) {
				cout << n/2 << " ";
				continue;
			}
		}
		else {
			if(a[i] >= n/2 - ct/2 && a[i] <= n/2 + ct/2) {
				cout << n/2 << " ";
				continue;
			}
		}
		cout << a[i] << " ";
	}
	
}