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
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for(int i = 0; i < k; i++) {
		cin >> a[i];
	}
	int ans = n;
	auto hf = [=](string s) -> bool {
		for(auto i : s) {
			if(binary_search(all(a),i-'0')) return 0;
		}
		return 1;
	};
	while(1) {
		if(hf(to_string(ans))) {cout << ans; return;}
		else ans++;
	}
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