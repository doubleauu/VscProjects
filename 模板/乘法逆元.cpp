#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1e9 + 7;


//费马小定理：使用快速幂；条件：当p为素数时；
ll fastPow(ll a, ll b, ll p) {
    ll ans = 1;
    ll base = a;
    while(b > 0) {
        if(b & 1) {
            ans = ans * base % p;
        }   
        base = base * base % p;
        b >>= 1;
    }
    return ans;
}

ll getInv(ll a, ll p){
    return fastPow(a, p-2, p);
}

// 欧几里得原理：
ll x, y;
int exgcd(int a, int b, int &x, int &y) { //我们需要在一次次回溯中修改x,y的值，要传引用
	if(b == 0) {
		x = 1; y = 0;
		return a;
	}else {
		int d = exgcd(b, a%b, x, y);  //此处不能直接返回，否则只求了公因数而没有修改x,y;
		int temp = x;
		x = y;   // 注意x可能为负数，得到后要特殊处理；
		y = temp - a/b * y;
		return d;
	}
}

int main() {
	ll x, y;
	ll gcd = exgcd(b, p, x, y);
	x = (x % p + p) % p;
}

//线性求逆元：
ll inv[100001];  //需要一个数组来存储答案；

void xianxing(ll n, ll p, ll inv[]) {
    inv[1] = 1;
    for(ll i = 2; i <= n; i++) {
        inv[i] = ((-(p/i) * inv[p%i])%p+p)%p;
    }
}