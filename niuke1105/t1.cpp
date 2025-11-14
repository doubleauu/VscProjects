/**
 * @brief: 逆向欧几里得原理？求递归n次得到结果且和最小的一组数，返回其和
 * 易错点：逆向的欧几里得原理恰好是斐波那契数列，而斐波那契数列增长非常快，应使用ll类型，防止溢出！！！
 * @comment: wc了，比赛时候就是因为int溢出一直过不了！！wc了
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0) return a;

    return gcd(b, a%b);
}

ll _gcd(ll a, ll b, ll n) {
    if(n == 0) return a+b;
    return _gcd(a+b, a, --n);  //注意n是先自减再参与运算，也可以直接写成n-1，不要n--！
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        ll n;
        cin >> n;
        if(n==0) { //一次不递归是特殊情况
            cout << 1 << endl;
            continue;
        }
        ll ans =_gcd(2,1,n-1);
        cout << ans << endl;
    }
}