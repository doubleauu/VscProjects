// Problem: E. Product Queries
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//@brief:
//@details:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5+10;
int isnp[maxn];
vector<int> prime;

void oula(int n) {
	isnp[0] = isnp[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!isnp[i]) {
			prime.push_back(i);
		}
		for(int p : prime) {
			if(p*i > n) break;
			isnp[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

int main() {
	oula(maxn);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n+1);
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a.begin()+1, a.end());
		
		bool has1 = false;
		if(a[1] == 1) has1 = true;
		if(has1) cout << 1 << " ";
		else cout << -1 << " ";
		for(int i = 2; i <= n; i++) {
			if(isnp[i]) {
				if(!has1) cout << -1 << " ";
				else if(binary_search(a.begin()+1,a.end(),i)) cout << 2 << " ";
			}else {
				
			}
		}
		cout << endl;
	}
}