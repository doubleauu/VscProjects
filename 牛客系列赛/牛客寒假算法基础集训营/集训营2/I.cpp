// Problem: 01回文
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/I
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
 		int n, m;
 		cin >> n >> m;
 		vector<string> a(n+1);
 		vector<int> cnt(2);
 		for(int i = 1; i <= n; i++) {
 			cin >> a[i];
 			for(int j = 0; j < m; j++) {
 				cnt[a[i][j]-'0']++;
 			}
 		}
 		for(int i = 1; i <= n; i++) {
 			for(int j = 0; j < m; j++) {
 				if(cnt[a[i][j]-'0'] > 1) {
 					cout << "Y";
 				}else cout << "N";
 			}
 			cout << endl;
 		}
 	}   
}