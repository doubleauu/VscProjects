// 使用前缀积减少每次求区间积的复杂度，因为同时出现了取模运算和除法运算，需要使用乘法逆元处理；
// 因为涉及数很大但是比较少，使用拓展欧几里得求乘法逆元，注意得到的乘法逆元可能为负数，要处理；
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll p = 1e9+7;

ll exgcd(ll a, ll b, ll &x, ll &y) { //我们需要在一次次回溯中修改x,y的值，要传引用, x就是乘法逆元
	if(b == 0) {
		x = 1; y = 0;
		return a;
	}else {
		ll d = exgcd(b, a%b, x, y);  //此处不能直接返回，否则只求了公因数而没有修改x,y;
		ll temp = x;
		x = y;   // 注意返回x 可能为负数结果；
		y = temp - a/b * y;
		return d;
	}
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    vector<ll> pre(n+1, 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = (a[i] * pre[i-1]) % p;  // 前i个数的乘积；
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        // cout << (pre[r] / pre[l-1])%p << " ";  // 涉及除法不能直接使用取余，转换为乘上乘法逆元；
        ll b = pre[l-1];
        ll x, y;
        ll gcd = exgcd(b, p, x, y);
        // cout << x << "\n";
        x = (x % p + p) % p; // 拓展欧几里得求得的x 可能为负数结果
        cout << ((pre[r]) *x )%p << " ";
    }
  
}