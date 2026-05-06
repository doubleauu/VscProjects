// Problem: 小L的三角尺
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/A
// Memory Limit: 512 MB
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
#define double long double
// int n,m,k,x,y,num,op,sum,cnt,res,ans;

struct M {
	double x=0;
	double y=0;
	double f=0;
	bool operator>(const M& m) const {
        return f < m.f; 
    }
};

// 求导,看 y 边对斜边长度的影响
double fun(double x, double y) {
	return y/sqrtl(x*x+y*y);
}
// 求对应x, f 下的 y 边长度；
double ff(double x, double y, double f) {
	return sqrtl(f*f*x*x/(1-(f*f)));
}
void solve() {
	int n, w;
	cin >> n >> w;
	priority_queue<M,vector<M>,greater<M>> pq;
	M t;  pq.push(t);
	set<double> v;
	v.insert(0);
	for(int i = 1; i <= n; i++) {
		M m;
		cin >> m.x >> m.y;
		m.f = fun(m.x,m.y);
		pq.push(m);
		v.insert(m.f);
	}
	double now = pq.top().f;  // 当前目标；
	while(w > 0) {
		if(pq.top().f == 0) break;
		M m = pq.top();
		pq.pop();
		
		auto i = v.find(m.f); i--;
		now = *i;
		v.erase(m.f);
		
		double y1 = ff(m.x,m.y,m.f);
		double y2 = ff(m.x,m.y,now);
		// cerr << (int)(y1>y2) << endl;
		int tt = ceil(y1-y2-1e-7);  // 防止浮点数误差导致加一
		// cout << y1-y2 << " " << tt << endl;
		if(w < tt) {
			m.y -= w; w = 0;
			m.f = fun(m.x, m.y);
			pq.push(m);
		}else {
			w -= tt;
			m.y -= tt;
			m.f = fun(m.x,m.y);
			// cerr << (int)(fun(m.x, m.y)==now);
			pq.push(m);
			v.insert(m.f);
		}
	}
	
	double ans = 0;
	while(!pq.empty()) {
		M m = pq.top();
		pq.pop();
		ans += sqrtl(m.x*m.x+m.y*m.y);
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