// Problem: #10. [R2D]倍数问题
// Contest: Daimayuan Online Judge
// URL: https://bs.daimayuan.top/p/10
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 埃式筛思想；
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

const int N = 5e5+5;


int main() {
 	int n;
 	cin >> n;
 	vector<int> a(N+1);
 	for(int i = 1; i <= n; i++) {
 		int t;
 		cin >> t;
 		a[t]++;
 	}
 	
 	vector<int> ct(N+1);
 	for(int i = 1; i <= N; i++) {
 		for(int j = i; j <= N; j+= i) {
 			ct[i] += a[j];
 		}
 	}
 	
 	int q;
 	cin >> q;
 	while(q--) {
 		int x;
 		cin >> x;
 		cout << ct[x] << endl;
 	}
}