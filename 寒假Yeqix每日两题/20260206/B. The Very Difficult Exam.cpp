// Problem: B. The Very Difficult Exam
// Contest: Codeforces - XXII Spain Olympiad in Informatics, Online Qualifier 2
// URL: https://codeforces.com/gym/105478/problem/B
// Memory Limit: 256 MB
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
#define all(a) a.begin(), a.end()
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;  //64位能用；
const int p = 1e9+7;
const int N = 1e6+5;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = n - count(all(s),'?'); // 先加上一定能拿的分；
		
		int len = 0;
		char pre = '?';  // 初始化是为了排除开头的空
		for(char c : s) {
			if(c == '?') {
				len++;
			}else {
				if(pre != '?' && len) {
					ans += (pre != c || len > 1);
				}
				pre = c;
				len = 0;  // 前面的if语句已经处理了上一个片段的？，此处长度归零；
			}
		}
		cout << ans << endl;
	}   
}