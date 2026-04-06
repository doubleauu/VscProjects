// Problem: 小苯的时钟显示
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/130843/A
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
	int t;
	int h=0,m=0,s=0;
	cin >> t;
	while(t>=3600) {
		t-=3600;
		h++;
	}
	while(t>=60) {
		t-=60;
		m++;
	}
	s = t;
	cout << h << " " << m << " " << s;
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