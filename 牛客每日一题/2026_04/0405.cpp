// Problem: Kevin喜欢零(困难版本)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/252712
// Memory Limit: 2 MB
// Time Limit: 252712000 ms
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

int f2(int n) {
	int t = 0;
	while(1) {
		if(n%2==0) {
			t++;
			n /= 2;
		}else break;
	}
	return t;
}
int f5(int n) {
	int t = 0;
	while(1) {
		if(n%5==0) {
			t++;
			n /= 5;
		}else break;
	}
	return t;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n+1), p2(n+1), p5(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		p2[i] = p2[i-1] + f2(a[i]);
		p5[i] = p5[i-1] + f5(a[i]);
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int l2 = lower_bound(p2.begin()+i,p2.end(),p2[i-1]+k)-p2.begin();
		int r2 = upper_bound(p2.begin()+i,p2.end(),p2[i-1]+k)-p2.begin()-1;
		int l5 = lower_bound(p5.begin()+i,p5.end(),p5[i-1]+k)-p5.begin();
		int r5 = upper_bound(p5.begin()+i,p5.end(),p5[i-1]+k)-p5.begin()-1;
		if(l2==n+1 || l5==n+1) continue;
		int l = max(l2,l5), r = max(r2,r5);
		ans += r-l+1;
	}
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}