// Problem: B. Seats
// Contest: Codeforces - Codeforces Round 1077 (Div. 2)
// URL: https://codeforces.com/contest/2188/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

int main() {
 	int t;
 	cin >> t;
 	while(t--) {
 		int n;
 		cin >> n;
 		string s;
 		cin >> s;
 		if(n == 1) {
 			cout << 1 << endl;
 			continue;
 		}
 		s = " " + s;
 		int ct = 0;
 		int ans = 0;
 		int l, r;
 		for(int i = 1; i <= n; i++) {
 			if(s[i] == '1') ct++;
 			// ... existing code ...
             if(s[i] == '0') {
                 l = i;
                 while(i < n && s[i+1] == '0'){
                     i++;
                 }
                 r = i;
                 int sz = r-l+1;
                
                // 计算这个区间需要覆盖的实际长度
                // 默认两头都被'1'覆盖，实际需要填补的长度是 sz - 2
                int need_cover_len = sz - 2;

                if (l == 1 && r == n) {
                    // 特判：全都是0，两头都没有人，需要覆盖整个长度
                    need_cover_len = sz;
                } else if (l == 1) {
                    // 开头是0，左边没人，右边有人，右边的'1'覆盖了第r个位置，只需覆盖 sz - 1
                    need_cover_len = sz - 1;
                } else if (r == n) {
                    // 结尾是0，左边有人，右边没人，左边的'1'覆盖了第l个位置，只需覆盖 sz - 1
                    need_cover_len = sz - 1;
                }

                if (need_cover_len > 0) {
                    // 向上取整公式：(x + 2) / 3
                    ans += (need_cover_len + 2) / 3;
                }
                
             }
// ... existing code ...
 		}
 		cout << ans+ct << endl;
 	}
}