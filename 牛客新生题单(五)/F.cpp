// Problem: 国际裁判带师
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/126270/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	int ct = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i]=='a') {
			a++;
			if(a > 9) {
				b++; a = 0;
			}
		}else {
			c++;
			if(c > 9) {
				d++; c = 0;
			}
		}
		ct += !a + !b + !c + !d;
	}
	cout << ct;
	
}