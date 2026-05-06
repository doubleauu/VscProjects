// Problem: 左右左右左左右，左右左左右
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127265/C
// Memory Limit: 512 MB
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

int gcd(int a, int b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, a0, a1;
		cin >> n >> a0 >> a1;
		if(a1 == 0) {
			for(int i = 1; i <= n; i++) cout << 0;
			cout << endl;
			continue;
		}
		if(a0 == 0) {
			for(int i = 1; i <= n; i++) cout << 1;
			cout << endl;
			continue;
		}
		if(a0 == a1) {
			string s;
			string st = "01";
			int t = n/2;
			while(t--) {
				// s += st;
				cout << st;
			}
			if(n%2!=0) cout << 0; // s.pb('0');
			// cout << s << endl;
			cout << endl;
			continue;
		}
		int g = a0*a1/gcd(a0,a1);
		int t1 = g/a0, t0 = g/a1;
		// cout << t1 << t0 << endl;
		string s;
		int ct0 = 0, ct1 = 0;
		while(!(t1==0 && t0==0) && s.size() <= n) {
			int a = a0*ct1, b = a1*ct0;
			int at = a+a0;
			int bt = b+a1;
			// cout << at << " " << bt << endl;
			if(abs(at-b) < abs(bt-a)) {
				t1--;
				ct1++;
				s.pb('1');
			}else{
				t0--;
				ct0++;
				s.pb('0');
			}
			// cout << s << endl;
		}
		int tn = s.size();
		if(tn == n) {
			cout << s << endl;
			continue;
		}
		string ans;
		int ts = n/tn;
		while(ts--) {
			// ans += s;
			cout << s;
			// ans += '0';
		}
		cout << s.substr(0,n%tn);
		cout << endl;
		// ans.append(s,0,n%tn);
		// cout << ans << endl;
		
	}
}