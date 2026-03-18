// Problem: Digital Folding
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;

int main() {
 	int t;
 	cin >> t;
 	while(t--) {
 		ll l, r;
 		cin >> l >> r;
 		int rsz = to_string(r).size();
 		ll t = 1;
 		for(int i = 1; i < rsz; i++) t *= 10;
 		if(r == t) {
 			if(l==r) {
 				cout << 1 << endl;
 				continue;
 			}
 			string s = to_string(r-1);
 			reverse(s.begin(),s.end());
 			cout << s << endl;
 		}else {
 			string ls = to_string(l), rs = to_string(r);
 			if(ls.size() < rs.size())l = t+1;  // 只有长度小的情况下才变，否则区间可能会变大
 			ls = to_string(l), rs = to_string(r);
 			for(int i = 0; i < rsz; i++) {
 				if(ls[i] != rs[i]) {
 					if(i == rsz-1) continue;
 					bool all9 = 1;
 					for(int j = i+1; j < rsz; j++) { // 此处应该是从i+1位开始比较
 						if(rs[j] != '9') {
 							all9 = 0;
 							break;
 						}
 					}
 					if(!all9)rs[i] = rs[i]-1;  // rs[i] 不可能是0，因为r一定比l大
 					while(i < rsz-1) rs[++i] = '9';
 				}
 			}
 			while(rs.size() > 1 && rs.back() == '0') {
 				rs.pop_back();  // 字符串函数也能用？？？
 			}
 			reverse(rs.begin(),rs.end());
 			cout << rs << endl;
 		}
 	}   
}