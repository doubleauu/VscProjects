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

// 一个数不动，暴力另一个数字
// 因为一个数的二进制表示位数很小，可以直接暴力；
void solve() {
	int x, y;
	cin >> x >> y;
	int ma = x > y ? x : y;
	int mi = 1LL*x+y-ma; // 防止int溢出
	int ans = ma;
	while(mi>0) {
		ans = max(ans,ma^mi);
		mi >>= 1;
	}
	ma = x < y ? x : y;
	mi = 1LL*x+y-ma;
	// int ans = ma;
	while(mi>0) {
		ans = max(ans,ma^mi);
		mi >>= 1;
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