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
	double sum = 0;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int t = floor(sum/n+0.5);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += (a[i]-t)*(a[i]-t);
	}
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