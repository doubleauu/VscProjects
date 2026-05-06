// Problem: C. [R44C]贺卡
// Contest: Daimayuan Online Judge
// URL: https://bs.daimayuan.top/p/271?tid=694f7ac529acac0b69676c65
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 多次查询，跑前缀和即可；
// 因为矩形是堆叠形成，所以只前缀和记录每个梯度左边的高度
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n+1);
	vector<ll> ans(n+1);
	for(int i = 1;i <= n; i++) {
		cin >> a[i];
		ans[i] = ans[i-1] + abs(a[i]-a[i-1]);
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		
		cout << ans[r]-ans[l]+(r-l+1)*2+a[l]+a[r] << endl;
	}
}