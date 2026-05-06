//判断奇数偶数，只需要看二进制数中最后一位即可，一个区间中只要有一个数的最后一位为1，区间或结果就是奇数；
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    vector<ll> preb(n+1);  // 前缀和
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] & 1;  //取二进制最后一位数字；
        // preb[i] = preb[i-1] + b[i]; //以 a[i] 为终点有几个奇数；
    }

    ll ans = 0;
    int t = 0;  //存储当前 0 - i 区间中的最后一个奇数；
    for(ll i = 1; i <= n; i++) {  // 以 a[i] 为结尾的有趣的区间的个数；
        if(b[i]) {
            t = i;
            ans += i;  // 如果这个数是奇数，那其前面任意数做开头都能构成一个有趣的区间；
        }
        else ans += t; // 如果这个数是偶数，则其构成有效区间的个数等于其前面的第一个奇数的有趣区间数量，因为偶数想构成有趣区间必须包含前面的第一个奇数；
    }
    
    cout << ans;
}