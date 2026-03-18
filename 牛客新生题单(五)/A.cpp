// Problem: Kevin逛超市 2 (简单版本)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/126270/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
	while(t--) {
		double n, x, y;
		cin >> n >> x >> y;
		vector<double> a(n+1);
		double ans = 0;
		int ct = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			ans += a[i];
			if(a[i] >= y) ct++;
		}
		
		if(n == 1) {
			double sum = max(min(a[1],y),a[1]*(100-x)/100);
			cout << ans-sum << "\n";
			continue;
		}
		
		sort(a.begin()+1,a.end());
		
		double sum = 0;
		if(ct > 1) {
			sum += a.back()*(100-x)/100;
			sum += y;
		}else if(ct < 1) {
			sum += a.back();
			sum += a[a.size()-2]*(100-x)/100;
		}else {
			double sum1 = y+a[a.size()-2]*(100-x)/100;
			double sum2 = a[a.size()-2]+a.back()*(100-x)/100;
			sum = max(sum1,sum2);
		}
		cout << fixed << ans-sum << "\n";
	}
}