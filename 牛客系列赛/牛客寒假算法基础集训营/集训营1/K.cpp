// Problem: Constructive
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/K
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
 		int n;
 		cin >> n;
 		if(n == 1) {
 			cout << "YES" << endl;
 			cout << 1 << endl;
 			continue;
 		}
 		if(n == 3) {
 			cout << "YES" << endl;
 			cout << 1 << " " << 2 << " " << 3 << endl;
 			continue;
 		}
 		cout << "NO" << endl;
 	}   
}