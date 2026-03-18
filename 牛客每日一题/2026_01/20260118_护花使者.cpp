//贪心策略，由局部最优到全局最优；
//每次搬运性价比最高的牛，为局部最优；
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct M{
    ll t;
    ll d;
};

bool comp(M m1, M m2) {
    return double(m1.d)/m1.t > double(m2.d)/m2.t;  //按性价比排；
}

int main() {
    ll n;
    cin >> n;
    vector<M> a(n+1);
    ll ctime = 0;
    ll ctd = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].d;
        ctime += a[i].t * 2;
    }

    sort(a.begin()+1, a.end(), comp);

    ll ans = 0;
    ll time = 0;
    for(ll i = 1; i <= n; i++) {
        ans += a[i].d * time;
        time += a[i].t*2;
    }

    cout << ans << "\n";

}