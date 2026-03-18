// Problem: スピカの天秤
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120563/G
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
#define all(a) a.begin(), a.end();
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
 		int n, m;
 		cin >> n >> m;
 		vector<int> a(n+1), b(m+1);
 		ll cnt1 = 0, cnt2 = 0;
 		for(int i = 1; i <= n; i++) {
 			cin >> a[i];
 			cnt1 += a[i];
 		}
 		for(int i = 1; i <= m; i++) {
 			cin >> b[i];
 			cnt2 += b[i];
 		}
 		if(cnt1 == cnt2) {
 			cout << 1 << endl;
 			continue;
 		}
 		if(cnt1 < cnt2) {
 			sort(b.begin()+1,b.end());
 			int ans = 0;
 			while(!(cnt1 >= cnt2)) {
 				cnt2 -= b.back();
 				b.pop_back();
 				// cout << b.back() << endl;
 				ans++;
 			}
 			cout << ans << endl;
 			continue;
 		}
 		if(cnt1 > cnt2) {
 			sort(a.begin()+1,a.end());
 			int ans = 0;
 			while(!(cnt1 < cnt2)) {
 				cnt1 -= a.back();
 				a.pop_back();
 				ans++;
 			}
 			cout << ans << endl;
 			continue;
 		}
 		
 	}
}