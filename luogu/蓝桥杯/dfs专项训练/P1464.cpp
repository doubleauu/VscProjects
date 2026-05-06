// Problem: P1464 [PacNW 1999] Function
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1464
// Memory Limit: 125 MB
// Time Limit: 1000 ms
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
// 注意题目范围，开ll;
// 了解记忆化搜索；
ll v[25][25][25];
ll w(ll a, ll b, ll c) {
	if(a<=0 || b<=0 || c<=0) return 1;
	if(a>20 || b>20 || c>20) return w(20,20,20);  // 此处表明真正有用范围只有20！！
	if(v[a][b][c]!=-1) return v[a][b][c];
	if(a < b && b < c) {
		v[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		return v[a][b][c];
	}
	v[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
	return v[a][b][c];
}
void solve() {
	memset(v,-1,sizeof(v));
	ll a, b, c;
	//持续输入；
	while(cin >> a >> b >> c) {
		if(a==-1&&b==-1&&c==-1) break;
		printf("w(%lld, %lld, %lld) = %d\n",a,b,c,w(a,b,c));
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