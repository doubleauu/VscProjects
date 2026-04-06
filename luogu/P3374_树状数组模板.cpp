// Problem: P3374 【模板】树状数组 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3374
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;

vector<ll> tree;
int n, m;

// lowbit:二进制中最低位 1 及其后面的零组成的数字
int lowbit(int x) return x & -x;

// 区间求和：[1,x]
ll pre(int x) {
    ll tsum = 0;
    for(; x ; x -= lowbit(x)) {
        tsum += tree[x];
    }
    return tsum;
}

// 区间求和：[l,r]
ll sum(int l, int r) {
    return pre(r) - pre(l-1);
}

// 单点修改：
void add(int x, int k) {
    for(; x<=n ; x+=lowbit(x)) {
        tree[x] += k;
    }
}

void solve() {
	cin >> n >> m;
	tree.resize(n+1);
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		add(i,k);
	}
	while(m--) {
		int op;
		cin >> op;
		if(op==1) {
			int x, k;
			cin >> x >> k;
			add(x,k);
		}else {
			int x, y;
			cin >> x >> y;
			cout << sum(x,y) << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}