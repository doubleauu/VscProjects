// Problem: H. Heavy Sort
// Contest: Codeforces - 2021 Ateneo de Manila Senior High School Dagitab Programming Contest (Mirror)
// URL: https://codeforces.com/gym/102911/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
// 目标：求比当前高的垃圾重量和

vector<ll> bit;
int n;
int lowbit(int x) {
	return x&-x;
}
ll pre(int x) {
	ll t = 0;
	for(; x ; x-=lowbit(x)) t+=bit[x];
	return t;
}

ll sum(int l, int r) {
	return pre(r) - pre(l-1);
}

void add(int x, int k) {
	for(; x <= n; x+=lowbit(x)) bit[x]+=k;
}

void solve() {
	cin >> n;
	bit.assign(n+1,0);
	vector<ll> h(n+1), w(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	
	// 对 h 离散化；
	vector<ll> b(h.begin()+1,h.end());
	sort(all(b));
	b.erase(unique(all(b)),b.end());
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int rk = lower_bound(all(b),h[i])-b.begin()+1;
		ll total = sum(rk+1,n);  // h[i] 前更高的垃圾总重量
		ans += w[i]*total;
		add(rk,w[i]);
	}
	cout << ans << endl;
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