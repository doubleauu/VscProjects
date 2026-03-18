// Problem: 比赛安排（PDF题面存放于本题）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/A
// Memory Limit: 2048 MB
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
 		int a, b, c;
 		cin >> a >> b >> c;
 		int t1 = abs(a-b);
 		int t2 = abs(a-c);
 		int t3 = abs(b-c);
 		if(t1 > 1 || t2 > 1 || t3 > 1) {
 			cout << "NO" << endl;
 		}else {
 			cout << "YES" << endl;
 		}
 	}   
}