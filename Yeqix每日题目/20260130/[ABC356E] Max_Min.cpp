// Problem: AT_abc356_e [ABC356E] Max/Min
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_abc356_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
using namespace std;
using ll = long long;

const int  N = 1e6;
// ll a[N];

int main() {
 	int n;
 	cin >> n; 
 	vector<ll> pre(N+1);
 	for(int i = 1; i <= n; i++) {
 		int x;
 		cin >> x;
 		pre[x]++; // 表示出现频率
 	}
 	
 	for(int i = 1; i <= N; i++) {
 		pre[i] += pre[i-1];  // 表示小于等于 i 的元素数量
 	}
 	ll ans = 0;
 	for(int i = 1; i <= N; i++) {
 		ll cnt = pre[i] - pre[i-1];  // 数字 i 出现的次数；
 		if(!cnt) continue;
 		for(int j = i; j <= N; j += i) {
 			if(j == i) ans += cnt*(pre[min(N,j+i-1)]-pre[j]);
 			else ans += cnt*(j/i)*(pre[min(N,j+i-1)]-pre[j-1]);
 		}
 		ans += cnt*(cnt-1)/2;
 	}
 	cout << ans << endl;
}