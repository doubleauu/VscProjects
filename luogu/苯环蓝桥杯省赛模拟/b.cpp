// Problem: P15964 编程比赛
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P15964
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
	ll a = 789456, b = 654321;
	ll ta = 567890, tb = 876543;
	ll an = 901234, bn = 500001;
	ll ans = 0;
	for(int i = 1; i <= an; i++) {
		ll t = a+ta*(i-1);
		if(t < b) ans += bn;
		else {
			// 看第二轮已经进行了多少场；
			int j = (t-b)/tb+1;
			// 注意第二轮可能已经结束！！！
			if(j<bn) ans += bn-j;
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