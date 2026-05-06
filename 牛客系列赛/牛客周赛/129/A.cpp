// Problem: 小红的大小判断
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127264/A
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
 	ll x;
 	cin >> x;
 	if(x > x*x) cout << "left" << endl;
 	else if(x == x*x) cout << "equal" <<endl;
 	else cout << "right" << endl;
}