// Problem: #69. [R12C]训练指令
// Contest: Daimayuan Online Judge
// URL: https://bs.daimayuan.top/p/69
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 队列问题；
// 我们每次需要增加一个排头，则在头部追加，想到双端队列；
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

int main() {
	int n,m;
	cin >> n >> m;
	deque<int> dq;

	for(int i =1; i<=n; i++) {
		dq.pb(i);
	}
	
	while(m--) {
		int t;
		cin >> t;
		dq.push_front(t);
		
	}
	// 操作越靠后，则在队列中就越靠前，输出第一次的即可；
	vector<bool> b(n+1);
	for(int i : dq) {
		if(!b[i]) {
			cout << i << " ";
			b[i] = 1;
		}
	}
}