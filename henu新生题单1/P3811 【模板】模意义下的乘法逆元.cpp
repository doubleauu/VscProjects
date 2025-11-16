/**
 * @brief:给定 n,p 求 1∼n 中所有整数在模 p 意义下的乘法逆元。
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll inv[3000010]; //数组太大，不能定义到栈上，，普通数组初始化更快

//线性求逆元
void xianxing(ll n, ll p, ll* inv) {
    inv[1] = 1;
    for(ll i = 2; i <= n; i++) {  //需要先求出第一个逆元，循环从第二个开始,防止改变第一个逆元的值
        inv[i] = ((-(p/i) * inv[p%i])%p + p)%p;
    }
}
int main() {
    ll n, p;
    scanf("%lld%lld",&n,&p);
    xianxing(n, p, inv);

for(ll i = 1; i <= n; i++){
    // cout << inv[i] << endl;
    printf("%lld\n",inv[i]);
}


#if 0
/**
 * @brief:使用线性求逆元，复杂度最低；
 */
 
void xianxing(ll n, ll p, vector<ll>& inv) {
    inv[1] = 1;
    for(ll i = 2; i <= n; i++) {  //需要先求出第一个逆元，循环从第二个开始,防止改变第一个逆元的值
        inv[i] = ((-(p/i) * inv[p%i])%p + p)%p;
    }
}

int main() {
    ll n, p;
    cin >> n >> p;
    vector<ll> inv(n+1);
    xianxing(n, p, inv);

for(ll i = 1; i <= n; i++){
    cout << inv[i] << endl;
}
#endif

}
#if 0
//使用扩展欧几里得算法

//欧几里得（辗转相除法）求最大公约数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

//扩展欧几里得，利用欧几里得算法的回溯求裴蜀定理的唯一解，同时求最大公约数
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {  //最里层递归
        x = 1; y = 0;
        return a;
    }
    ll d = exgcd(b, a%b, x, y);  //向上层回溯
    ll k = x;
    x = y;  //使用k存值防止x被覆盖
    y = k - a/b*y;
    return d; //最上层计算出唯一解同时返回最大公约数
}

int main() {
    ll n,p;
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        ll x,y;
        exgcd(i,p,x,y);
        cout << (x%p + p)%p << endl; //注意x可能为负值
    }
}
#endif



#if 0 
//使用费马小定理和快速幂

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
int main() {
    ll n,p;
    cin >> n >> p;
    for(ll i = 1; i <= n; i++) {
        cout << getInv(i, p) << endl;
    }
    return 0;
}
#endif