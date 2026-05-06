// Problem: 智乃的最大子段和取模
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120565/E
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
// #define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
struct M {
	int l = 0;
	int r = 0;
	int v = 0;
	bool operator>(const M& m) const {
        return v < m.v; 
    }
};
void solve() {
	// priority_queue<M,vector<M>,greater<M>> pq;
	ll n, p;
	cin >> n >> p;
	vector<ll> a(n);
	int pos = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] == p-1) pos = i;
	}
	if(pos) {
		cout << pos << " " << pos << " " << p-1 << endl;
		return;
	}
	M m;
	m.v = a[0];
	// pq.push(m);
	
	// deque<int> dq;
	// dq.pb(a[0]);
	int l = 0, r = 0; // 表示当前区间；
	ll tsum = a[0];
	
	while(r < n-1) {
		while(tsum < p && r < n-1) {
			r++;
			// dq.pb(a[r]);
			tsum += a[r];
			if(tsum < p && tsum > m.v) {
				m.l = l, m.r = r, m.v = tsum;
			}
			// r++;
		}
		while(tsum >= p) {
			// dq.pop_front();
			tsum -= a[l];
			l++;
			if(tsum < p && tsum > m.v) {
				m.l = l, m.r = r, m.v = tsum;
			}
		}
	}
	cout << m.l << " " << m.r << " " << m.v;
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