// Problem: P15968 电梯接客
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P15968?contestId=314564
// Memory Limit: 512 MB
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

struct M {
	int f=0, num=0;
};

bool comp(M m1, M m2) {
	return m1.f <= m2.f;
}
void solve() {
	ll n, x, y, w;
	cin >> n >> x >> y >> w;
	vector<M> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i].f >> a[i].num;
	}
	sort(a.begin()+1,a.end(),comp);
	// 假设起始在最顶层；
	vector<ll> ans(y+1), pre(y+1);
	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		pre[i] = a[i]+pre[i-1];
		
	}
	// for(int i = 1; i <= n;) {
		// int t = i;
		// ll tsum = 0;
		// // 分组，每w个一组
		// // w可能很小，导致每一层操作多次，超时；
		// while(1) {
			// if(tsum+a[i].num > w) {
				// a[i].num -= w-tsum;
				// tsum = w;
				// ans[a[t].f]++;
				// break;
			// }else if(tsum+a[i].num == w) {
				// tsum = w;
				// a[i].num = 0;
				// ans[a[t].f]++;
				// i++;
				// break;
			// }else {
				// tsum += a[i].num;
				// a[i].num = 0;
				// i++;
				// if(i > n) {ans[a[t].f]++; break;}
			// }
		// }
	// }
	for(int i = 1; i <= n;) {
		int t = i;
		ll tsum = 0;
		// 分组，每w个一组
		// w可能很小，导致每一层操作多次，超时；
		while(1) {
			if(tsum+a[i].num > w) {
				a[i].num -= w-tsum;
				tsum = w;
				ans[a[t].f]++;
				break;
			}else if(tsum+a[i].num == w) {
				tsum = w;
				a[i].num = 0;
				ans[a[t].f]++;
				i++;
				break;
			}else {
				tsum += a[i].num;
				a[i].num = 0;
				i++;
				if(i > n) {ans[a[t].f]++; break;}
			}
		}
	}
	ll res = 0;
	int b = 1;
	for(int i = 1; i <= y; i++) {
		if(!ans[i]) continue;
		// 第一次接最远的；
		if(b) {
			b = 0;
			res += abs(x-i)+(y-i);
			res += (ans[i]-1)*2*(y-i);
			continue;
		}
		res += ans[i]*2*(y-i);
	}
	cout << res;
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