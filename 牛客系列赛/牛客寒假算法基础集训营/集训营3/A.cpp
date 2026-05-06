// Problem: 宙天
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120563/A
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
#define all(a) a.begin(), a.end();
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;

int main() {
 	int x;
 	cin >> x;
 	for(int i = 1; i <= x; i++) {
 		if(i*(i+1) == x) {
 			cout << "YES" << endl;
 			return 0;
 		}
 	}  
 	cout << "NO" << endl;
}