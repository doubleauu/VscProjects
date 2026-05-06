// Problem: 小红越级（easy）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125955/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 暴力过不了，题目是多次查询，考虑前缀和：
// 我们反向思路，前缀和跑舒适区间，记录舒适度
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n+1);
		vector<int> b(n+1);
		vector<int> ansa(n+5); // 前缀和：在 i 左右的曲目数量
		vector<int> ansb(n+5); // 前缀和：在 i 左右的曲目数量
		
		vector<int> v1; // 标记作用区间重叠；
		vector<int> v2; // 标记作用区间重叠；
		for(int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
			ansa[a[i]]++;
			ansa[a[i]-1]++;
			ansa[a[i]+1]++;
			ansb[b[i]]++;
			ansb[b[i]-1]++;
			ansb[b[i]+1]++;
			if(abs(b[i]-a[i]+1) < 6) {
				v1.pb(a[i]);
				v2.pb(b[i]);
			}
		}
		int tn = v1.size();
		while(q--) {
			int x;
			cin >> x;
			int ans = 0;
			// for(int i = 1; i <= n; i++) {
				// if(!((a[i] >= x-1 && a[i] <= x+1)||(b[i] >= x-1 && b[i] <= x+1))) {
					// ans++;
				// }
			// }
			ans += ansa[x] + ansb[x];
			for(int i = 0; i < tn; i++) {
				if((v1[i] >= x-1 && v1[i] <= x+1)&&(v2[i] >= x-1 && v2[i] <= x+1)) {
					ans--;
				}
			}
			
			cout << n-ans << " ";
		}
		cout << endl;
	}
}