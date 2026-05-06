// Problem: E - Knapsack 2
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_e
// Memory Limit: 1024 MB
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
	int n, m;
	cin >> n >> m;
	vector<int> w(n+1), v(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> v[i] >> w[i];
	}  
	vector<vector<ll> > dp(n+1,vector<ll>(1e5+1,1e10));
	for(int i = 1; i <= 1e5; i++) {
		dp[0][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(v[i] <= j) {
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
			}
		}
	}
	for(int i = 1e5; i >= 1; i--) {
		if(dp[n][i] <= m){
			cout << i << endl;
			break;
		} 
	}
}