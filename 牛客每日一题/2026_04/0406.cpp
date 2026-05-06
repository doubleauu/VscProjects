// Problem: 小苯的麦克斯
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/300248
// Memory Limit: 2 MB
// Time Limit: 300248000 ms
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
	vector<int> a(n+2);
	int ma = INT_MIN, pos = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] > ma) {
			ma = a[i];
			pos = i;
		}
	}
	if(a[pos] == 0) {
		cout << -1 << endl;
		return;
	}
	if(a[pos+1]==0 && a[pos-1]==0) {
		int mex = a[pos]==1 ? 2 : 1; 
		cout << ma-mex << endl;
	}else {
		cout << ma << endl;
	}
	
	
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