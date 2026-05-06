// Problem: Need Zero
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/L
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
 	int n;
 	cin >> n;
 	if(n%10 == 0) {
 		cout << 1 << endl;
 		return 0;
 	}
 	int t = n%10;
 	if(10%t == 0) {
 		cout << 10/t << endl;
 		return 0;
 	}else {
 		for(int i = 2; i <= 10; i++) {
 			if(i * n % 10 == 0) {
 				cout << i << endl;
 				return 0;
 			}
 		}
 	}
}