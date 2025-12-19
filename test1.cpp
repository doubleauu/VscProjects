// Problem: 小数字
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125447/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T;
	cin >> T;
	while(T--) {
		long long n;
        int m;
		cin >> n >> m;
		while(m > 0 && n >= 4) {
			n = (long long)ceill(sqrtl((long double)n));
			m--;
		}
		n -= m;
		cout << n << endl;
	}
}