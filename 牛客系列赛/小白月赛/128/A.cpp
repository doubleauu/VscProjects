// Problem: 模糊匹配
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127265/A
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

int main() {
 	int t;
 	cin >> t;
 	vector<char> a = {'I','l','1'};
 	vector<char> b = {'0','O'};
 	sort(a.begin(),a.end());
 	sort(b.begin(),b.end());
 	while(t--) {
 		int n;
 		cin >> n;
 		string s1, s2;
 		cin >> s1 >> s2;
 		bool c = 0;
 		for(int i = 0; i < n; i++) {
 			if(s1[i] == s2[i]) continue;
 			else if(binary_search(b.begin(),b.end(),s1[i])&&binary_search(b.begin(),b.end(),s2[i])){
 				continue;
 			}else if(binary_search(a.begin(),a.end(),s1[i])&&binary_search(a.begin(),a.end(),s2[i])) {
 				continue;
 			}else {
 				cout << "NO" << endl;
 				c = 1;
 				break;
 			}
 		}
 		if(!c) cout << "YES" << endl;
 	}
}