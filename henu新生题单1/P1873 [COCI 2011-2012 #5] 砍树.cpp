/**
 * @brief: 砍树问题，找到最小高度，得到目标木材；因为从高到低调整高度得到的木材使递增的，可以使用二分法，降低复杂度
 * @complexity: O(nlogm)
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//找到最高的树
ll maxh(ll max, ll i) {
    return max > i ? max : i;
}

//找到最低的树
ll minh(ll min, ll i) {
    return min < i ? min : i;
}
int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    vector<ll> th(n);  //tree high
    ll min = 400001, max = 0;
    for(ll& i : th) { 
        scanf("%lld", &i);
        min = minh(min, i);
        max = maxh(max, i);
    }

    ll ans = -1;
    while(min <= max) {                  //复杂度O(logm)
        ll sum = 0;
        ll mid = min + ((max - min)/2);  //从中间开始砍
        for(ll i : th) {
            if(i > mid) sum += (i-mid);  //复杂度O(n)
        }
        if(sum < m) {
            max = mid - 1;
        }else {           //因为有可能不存在恰好得到足够木材，所以只要sum大于m就要记录答案，并抬高高度
            ans = mid;
            min = mid + 1;
        }
        // if(sum > m) {
        //     min = mid + 1;  //保持左闭右闭的区间
        // }else if(sum < m) {
        //     max = mid - 1;
        // }else {
        //     ans = mid;
        //     min = mid + 1;  //继续抬高高度，找到最小高度；
        // }
    }
    printf("%lld", ans);
    return 0;
}