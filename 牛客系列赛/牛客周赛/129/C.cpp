// Problem: 小红的肥鹅健身房
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127264/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：使用队列存储：便于删除合并后的元素和添加新元素；
 	
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
 	int n, m, k;
 	cin >> n >> m >> k; 
 	deque<ll> a;
 	int t = n*m;
 	while(t--) {
 		int x;
 		cin >> x;
 		a.pb(x);
 	}
 	
 	ll cnt = 0;
 	ll ans = 0;
 	bool failed = false;
 	while(!failed) {
 		sort(a.begin(), a.end());

 		while(a.front() == 0) {
	 		a.pop_front();
	 	}
	 	int sz = a.size();
	 	for(int i = 0; i < sz; i++) {
	 		if(a[i] == a[i+1]) {
	 			a.pb(a[i]+1);
	 			ans++;
	 			if((a[i]+1)>=k) cnt++;
	 			a[i] = a[i+1] = 0;
	 		}
	 	}
	 	if(a.size() == sz) failed = true;
 	}
 	
 	cout << ans << " " << cnt << endl;
 	
 	
 	 
}