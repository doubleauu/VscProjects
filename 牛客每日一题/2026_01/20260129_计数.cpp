// 下一个丢失的数字可能跟前一个有关，动态规划？
// 数列求和；
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

const ll p = 1000000007;

// 分段处理，然后相乘；
struct M {
	int l, r;
	deque<int> dq;
} ;

int main() {
 	int n;
 	cin >> n;
 	vector<int> a(n+1);
 	vector<M> b;
 	vector<int> c(n+1);
 	for(int i = 1; i <= n; i++) {
 		cin >> a[i];
 		if(a[i] == 0) {
 			c[i] = 1;
 			M m;
 			m.dq.pb(i);
 			
 			if(i == 1) m.l = 1000;
 			else m.l = a[i-1];
 			
 			while(i < n && a[i+1] != 0) {
 				i++;
 				c[i] = 1;
 				m.dq.pb(i);	
 			}
 			
 			if(i == n) m.r = 1;
 			else m.r = a[i+1];
 			
 			b.pb(m);
 		}
 	}
 	
 	// ll ans = 0;
 	// for(int i = 1; i <= 1000; i++) {
 		// for(int j = i; j >= 1; j--) {
 			// for(int k = j; k >= 1; k--) {
 				// ans++;
 			// }
 		// }
 	// }
 	// cout << ans << endl;
 	int sz = b.size();
 	for(int i = 0; i < sz; i++) {
 		#define bq b[i].dq
 		#define bl b[i].l
 		#define br b[i].r
 		int t = br-bl+1;
 		
 		// for(int j = 0; j < tn; j++) {
 			// int pos = bq[j];
 			// cerr << pos << endl;
 			// if(j == 0) c[pos] = t;
 			// else {
 				// c[pos] = c[pos-1]*(br-bl+2)/2;
 			// }
//  			
 			// if(j == tn-1) ans = ans*c[pos]%p;
 		// }
 	}
 	cout << ans;
}