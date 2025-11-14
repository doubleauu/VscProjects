/**
 * @brief: 求给定数列指定长度的连续字段乘积的最大值，注意取模
 * @details: 使用双指针法（滑动窗口）; 注意除零错误  ;
 *           注意在取模运算中不能使用除法（过程中取模结果再除法运算结果会出错), 应使用乘法逆元
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200005];
ll MOD = 998244353;

ll powf(int x, int y) {  //用于初始化,避免数列字段全含0的特殊情况
    ll ans = 1;
    while(y >= x) {
        ans = ans * a[y]%MOD;
        y--;
    }
    return ans;
}

//快速幂
ll fastPow(ll a, ll b) {
    ll base = a;
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans*base % MOD + MOD) % MOD;
        }
        base = (base*base % MOD+ MOD) % MOD;
        b >>= 1;
    }
    return ans;
}
int main() {
    ll n,k;
    scanf("%lld%lld",&n,&k);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    ll pow = 1;
    int l = 0; int r = 0; 
    ll ans = powf(l,k-1);
    while(r-l <= k-1 && r < n) {
        pow = pow * a[r] % MOD;
        if(pow == 0) {
            l = r+1;
            pow = 1;
        }
        if(r-l == k-1) {
            ans = pow > ans ? pow : ans;
            pow = pow * fastPow(a[l], MOD-2) % MOD;
            l++;
        }
        r++;
    }
    cout << ans;
}
