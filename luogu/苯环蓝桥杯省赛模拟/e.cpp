// Problem: P15967 采矿文明
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P15967?contestId=314564
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
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> c(n), prec(n);
	for(int i = 1; i < n; i++) {
		cin >> c[i];
		prec[i] = prec[i-1]+c[i];
	}
	vector<ll> a(n+1), prea(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		prea[i] = prea[i-1]+a[i];
	}
	vector<ll> ans(n+1);
	ll res = 0;
	ll sum = 0;
	pq<ll,vector<ll>,greater<ll>> maxk;
	for(int i = 1; i <= n; i++) {
		maxk.push(a[i]);
		sum += a[i];
		if((int)maxk.size() > k) {
			sum -= maxk.top();
			maxk.pop();
		}
		// 只挖最多的 k 个矿洞
		// ll sum = 0;
		// 复制再排序会超时，使用优先队列！(自动排序的数据结构)
		// 我们每次要去掉小的，改用小项堆，小的在前面
		// vector<ll> t(a.begin(),a.begin()+i+1); // 注意这个是左闭右开区间！
		// sort(all(t),greater<int>());
		// for(int j = 0; j <= min(k-1,(ll)t.size()-1); j++) {
			// sum += t[j];
		// }
		
		
		ans[i] = min(sum,m-prec[i-1]);
		res = max(res,ans[i]);
	}
	cout << res;
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