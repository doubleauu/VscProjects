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
bool is(int n) {
	if(n<=1) return false;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n%i==0) return 0;
	}
	return 1;
}
void solve() {
	int n;
	cin >> n;
	// 乘法的收益更高，选择尽可能多的因数
	if(is(n)) {
		cout << n << endl;
		return;
	}
	int ans = 0;
	while(n>1) {
		for(int i = 2; i <= n; i++) {
			if(n%i==0) {
				n = n/i;
				ans += i;
				break;
			}
		}
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