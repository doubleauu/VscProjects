// Problem: 小红的神秘密码解锁
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127264/D
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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;

int main() {
	string s;
	cin >> s;
	vector<ll> a;
	for(int i = 0; i < s.size(); i++) {
		char c = s[i];
		int cnt = 0;
		while(s[i] == c) {
			cnt++;
			i++;
		}
		a.pb(cnt);
		i--;
	}
	int n = a.size();
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> pre(n+1);
	pre[0] = a[0];
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i-1]+a[i];
	}
	
	ll ans = 1;
	for(int i = 0; i < n; i++) {
		if(i == 0 || i == n-1) {
			ans += a[i]-1;
		}else {
			if(i < n-2) {
				ans += (n-2-i)*(a[i-1]-1);
				ans += (pre[n-1]-pre[i+1]-(n-2-i));
				// for(int j = i+1; j <= n-2; j++) {
					// ans += (a[j+1]-1);
				// }
			}
			ans += 2*(a[i]-1);
			ans += (a[i-1]-1);
			ans += (a[i+1]-1);
		}
	}
	cout << ans << endl;
	  
}