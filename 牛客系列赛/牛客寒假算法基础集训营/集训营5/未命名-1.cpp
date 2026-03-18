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
struct M {
	ll cnt = 0;
	ll s = 0;
	bool operator>(const M& m) const {
        return s > m.s; 
    }
};

void solve() {
	pq<M,vector<M>, greater<M>> p;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		M m;
		cin >> m.cnt >> m.s;
		p.push(m);
	}
	// for(int i = 1; i <= n; i++) {
		// cout << p.top().cnt << " " << p.top().s << endl;
		// p.pop();
	// }
	ll ans = 0;
	M m;
	// M m = p.top();  // 剩余的
	// p.pop();
	while(true) {
		if(p.size()==1&&p.top().cnt==1&&m.cnt==0) break;
		if(m.cnt==0) {
			M tm = p.top();
			p.pop();
			if(tm.cnt%2==0) {
				M tt;
				tt.cnt = tm.cnt/2;
				tt.s = tm.s*2;
				p.push(tt);
				ans = (ans + tt.cnt*tt.s%mod)%mod;
			}else {
				M tt;
				tt.cnt = tm.cnt/2;
				tt.s = tm.s*2;
				if(tt.cnt!=0) p.push(tt);
				ans = (ans + tt.cnt*tt.s%mod)%mod;
				m.cnt=1, m.s = tm.s;
			}
		}else {
			M tm = p.top();
			p.pop();
			m.s += tm.s;
			p.push(m);
			ans = (ans + m.s%mod)%mod;
			m.cnt=m.s = 0;
			tm.cnt--;
			if(tm.cnt>0) {
				if(tm.cnt%2==0) {
					M tt;
					tt.cnt = tm.cnt/2;
					tt.s = tm.s*2;
					p.push(tt);
					ans = (ans + tt.cnt*tt.s%mod)%mod;
				}else {
					M tt;
					tt.cnt = tm.cnt/2;
					tt.s = tm.s*2;
					if(tt.cnt!=0) p.push(tt);
					m.cnt=1, m.s = tm.s;
					ans = (ans + tt.cnt*tt.s%mod)%mod;
				}
			}
		}
		
	}
	// cout << p.top().s << endl;
	cout << ans;
	
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