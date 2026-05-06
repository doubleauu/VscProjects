// Problem: x?y?n!
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/F
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：两个数相邻；
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

string change(ll n) {
	string ans = "";
	while(n != 0) {
		ans.pb('0'+(n&1));
		n >>= 1;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
 		cin >> n;
 		string t = change(n);
 		int tsize = t.size();
 		int t0 = 0;
 		for(int i = tsize-1; i > 0; i--) {
 			if(t[i]=='0') t0++;
 			else break;
 		}
 		ll ans = n;
 		ans <<= (tsize-t0);
 		cout << ans << " " << ans+n << endl;
	}
 	
}