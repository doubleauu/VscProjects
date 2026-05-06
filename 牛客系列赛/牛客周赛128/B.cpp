// Problem: 小红的马卡龙定位
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127240/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//@brief:
//@details:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	int x1, x2, x3;
	int y1, y2, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	if(x1+x2 == 2*x3 && y1+y2 == 2*y3) {
		cout << 3 << endl;
	}
	if(x1+x3 == 2*x2 && y1+y3 == 2*y2) {
		cout << 2 << endl;
	}
	if(x3+x2 == 2*x1 && y3+y2 == 2*y1) {
		cout << 1 << endl;
	}
}