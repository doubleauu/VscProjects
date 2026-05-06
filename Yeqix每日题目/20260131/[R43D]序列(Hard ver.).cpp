// Problem: #266. [R43D]序列(Hard ver.)
// Contest: Daimayuan Online Judge
// URL: https://bs.daimayuan.top/p/266
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：因为判断好序列的标准是极差，与序列的顺序无关，我们可以先给序列排序，
 	然后每次取第 i 个元素作为子序列最小值，找到原序列中可满足的极大值：使用upper_bound()-1;
 	然后我们找这段子序列的子序列个数，首先第 i 个元素存在，后面的分存在和不存在两种情况，即 2^(sz-1);
 	可以提前处理 2 的阶乘；
 注意：每次加法或者乘法运算都要取模，防止溢出！
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
using namespace std;
using ll = long long;

const int p = 998244353;
const int N = 1e6+10;
ll pre[N];


int main() {
 	int n, k;
 	cin >> n >> k;
 	vector<int> a(n+1);
 	pre[0] = 1;
 	
 	for(int i = 1; i <= n; i++) {
 		cin >> a[i];
 		pre[i] = pre[i-1]*2%p;  // 阶乘上升很快，记得每次取模；
 	}
 	sort(a.begin()+1, a.end());
 	ll ans = 0;
 	for(int i = 1; i <= n; i++) {
 		int t = a[i]+k;
 		auto it = upper_bound(a.begin(),a.end(),t);
 		int sz = it-1 - a.begin()-i;
 		ans = (ans+pre[sz]%p)%p;
 	}
 	cout << ans <<endl;
}