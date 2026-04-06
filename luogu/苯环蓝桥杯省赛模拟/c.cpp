// Problem: T623315 跳柱文明
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T623315?contestId=314564
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
	int n, x;
	cin >> n >> x;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 2; i <= n; i++) {
		int t = a[i]-a[i-1];
		if(t > 1 || t < -x) {
			cout << "Lose" << endl;
			return;
		}
	}
	cout << "Win" << endl;
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