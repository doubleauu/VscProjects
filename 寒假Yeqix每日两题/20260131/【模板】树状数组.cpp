// Problem: P3374 【模板】树状数组 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3374
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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


const int maxn = 1e6+5;
ll tree[maxn];
int n;

inline int lowbit(int x) {
	return x & -x;
}

void add(int x, ll k) { /// 将第 x 个位置加上 k;
	while(x <= n) {
		tree[x] += k;
		x += lowbit(x);
	}
}

ll getsum(int x) {  // a[1]..a[x]的和
	int ans = 0;
	while (x > 0) {
	    ans = ans + tree[x];
	    x = x - lowbit(x);
	}
	return ans;
}

ll query(int l, int r) {
	return getsum(r) - getsum(l-1);
}

int main() {
 	int m;  // n 已经定义全局变量，此处不要再重复定义，会覆盖！
 	cin >> n >> m;
 	int pos = 1;
 	int t = n;
 	
 	for(int i = 1; i <= n; i++) {
 		int k;
 		cin >> k;
 		add(i,k);
 	}
 	while(m--) {
 		int op;
 		cin >> op;
 		if(op == 1) {
 			int x,k;
 			cin >> x >> k;
 			add(x,k);
 		}
 		if(op == 2) {
 			int l, r;
 			cin >> l >> r;
 			cout << query(l,r) << endl;
 		}
 	}
}