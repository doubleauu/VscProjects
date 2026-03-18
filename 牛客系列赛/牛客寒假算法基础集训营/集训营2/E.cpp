// Problem: 01矩阵
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/E
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
 	int n;
 	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		a[i].append(n-i,'0');
		a[i].append(i,'1');
	}
	for(int i = 1; i < n; i += 2) {
		for(int j = n-1; j > n-1-i; j--) {
			swap(a[i][j],a[n-1-j][n-1-i]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}