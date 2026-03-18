// Problem: 小红的大小再判断
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127264/B
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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;

int main() {
 	 string s;
 	 cin >> s;
 	 string s1 = s;
 	 reverse(s1.begin(),s1.end());
 	 if(s == s1) cout << "equal" <<endl;
 	 else if(s > s1) cout << "left" << endl;
 	 else cout << "right" << endl;
}