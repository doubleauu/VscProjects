// Problem: 小苯的观景路线
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/130843/C
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
void solve() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	int ans = 0;
	int p = 0;
	int l = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i]-a[l]>=p) {
			ans++;
			p++;
			l = i;
		}
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