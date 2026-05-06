/*
 思路：动态规划题，目标子串是一步步拼接形成，从前往后选取字符，理解其中的状态转移方程
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const ll p = 2000120420010122;  //注意int类型会溢出；
const int N = 1e6+5;

ll dp0,dp1,dp2;

int main() {
 	string s;
 	while(cin >> s) {
 		dp0 = dp1 = dp2 = 0;
 		ll ans = 0;
 		for(char c : s) {
 			char t = tolower(c);
 			if(t == 'w') dp1 += dp0;
 			else if(t == 'b') dp2 += dp1;
 			else if(t == 'c') {
 				dp0++;
 				ans += dp2;
 			}
 		}
 		cout << ans%p << endl;
 	}   
}