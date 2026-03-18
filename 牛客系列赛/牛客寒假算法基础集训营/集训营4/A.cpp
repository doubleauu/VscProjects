// Problem: 本场比赛灵感来源于树状数组出题组
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/A
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
	int tn = ceil((n-1)*0.8);
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	int maxn = a[tn];
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] >= maxn) sum += a[i];
	}
	
	// for(int i = tn-1; i < n; i++) sum += a[i];
	cout << sum << endl;
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