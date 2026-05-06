#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e7;
/*
url: https://www.nowcoder.com/practice/eba3598e1e80420c9d4f6df5539ab9f1?channelPut=tracker2
如果两个数字都是偶数，那么直接就能输出 0 就行
如果两个数都是奇数，那么直接加一即可
那么需要我们讨论的情况就是 一个奇数一个偶数；
根据样例二我们发现：~~这个样例给的真好~~
经过第一次迭代：假设 a > b; (a+c)%(b+c)一定是等于 a-b;
gcd(a+c,b+c) = gcd(b+c,a-b);
a, b一个是奇数，一个是偶数，结果一定是奇数了，~~如果是偶数就好说了~~
我们考虑这个数是不是质数：
1. 如果是质数，我们就比较 b 与 a-b 的大小，b 小就 +c 将其补到 a-b, 否则就将其补到刚好是 a-b 的倍数即可；使得 gcd 等于 a-b；
2. 如果不是质数，我们就试图找到 a-b 的最小因数，并将 b 补到刚好是其倍数即可；
问题就是 1e14 的范围我们如何快速找到最小因数；
想到判断质数的方法：暴力遍历，欧拉筛(1e7), 过大用我们欧拉跑出来的数除，看能否除尽即可（因为质数是比较少的，复杂度应该够）；

好像忘记了不存在的情况：
如果两者差是 1，我们无论如何构造，gcd 都只能是 1，否则都能构造！

wa了四个点。。。
wc我知道了，我选择的是 d 的最小因数作为最大公因数，但是此时的 c 不一定是最小的，应该把所有因数遍历一遍；
666 53个测试点，又wa了3个，我真没招了；
原来是只加了小质因数，忘记了加上除后产生的大质因数

~~发现这居然是一道 1800 的题，我也是好起来了~~
#### 总结：此题的关键就是将 b 补到 d 的质因数的倍数
1. 开不了 1e7 的数组，使用bitset
2. 判断很大的质数是否质数，先跑欧拉筛(1e7)，在使用已知质数试除；
*/ 
ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

bitset<N+5> isnp; // 开不了 1e7 的数组，使用bitset；
vector<int> prime;
void oula(int n) {
    isnp[0] = isnp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!isnp[i]) prime.pb(i);
        for(auto p : prime) {
            if(p*i>n) break;
            isnp[p*i] = 1;
            if(i%p==0) break;
        }
    }
}
void solve() {
    ll a, b;
    cin >> a >> b;
    if(a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    if(gcd(a,b)!=1) {
        cout << 0 << endl;
        return;
    }
    if(a%2!=0 && b%2!=0) {
        cout << 1 << endl;
        return;
    }
    if(a-b==1) {
        cout << -1 << endl;
        return;
    }
    oula(N);
    ll d = a-b;
    ll g = -1;
    vector<ll> gcd1;
    for(auto i : prime) {
        if(d%i == 0) {
            g = i;
            gcd1.pb(i);
            gcd1.pb(d/i);  // 此处别忘了将大的质因数也输入进去
            // break;    // 此处不应该退出，我们要找到所有可以实现的因数   
        }
    }
    if(g == -1) {
        if(b <= a-b) cout << a-b-b << endl;
        else cout << a-b-(b-(b/(a-b)*(a-b))) << endl;
    }else {
        ll ans = LLONG_MAX;
        for(auto g : gcd1) {
            if(b <= g) ans = min(ans,g-b);
            else ans = min(ans,g-(b-(b/g*g)));
        }
        cout << ans << endl;
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