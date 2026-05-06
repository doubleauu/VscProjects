#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll mod = 1e9+7;
const ll N = 1e6+5;
//url:https://www.luogu.com.cn/problem/P16237?contestId=320659
/*
url: 
*/
// 题目要求最少跳线，每一块儿的电脑连接正常，我们将其视为一个整体，使用dfs进行探索，v[i]标记
// 第一思路，从第一个为基准，将其与其他部分进行跳线连接，因为题目还要求每个电脑连接线尽量少
// 则我们每次找出已连接堆中的最小值，想到优先队列结构，但不能修改，则每次pop出最小值在push+1
// 但是wa了一部分点，想到我们要求每台机器的跳线应该尽可能少，因此我们每次应该接入尽可能大的堆，这样就有更多的电脑提供接口
// 则分两步做，先dfs将所有电脑分块，再将其按大到小的顺序接入即可；

bool comp(vector<int> a, vector<int> b) {
    return a.size() > b.size();
}
void solve() {
	ll n, m;
    cin >> n >> m;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    vector<vector<ll>> a(n+1);
    for(ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    vector<ll> v(n+1);
    vector<vector<int>> res;
    vector<int> t;
    function<void(ll)> dfs = [&](ll now) {
        for(auto i : a[now]) {
            if(v[i]) continue;
            v[i] = 1;
            t.pb(i);
            cerr << i << endl;
            // pq.push(0);
            dfs(i);
        }
        // res.pb(t);

    };
    // v[1] = 1;
    // pq.push(0);
    // dfs(1,vector<int>(1,1));
    
    for(int i = 1; i <= n; i++) {
        if(v[i]) continue;
        v[i] = 1;
        t.resize(0);
        t.pb(i);
        dfs(i);
        res.pb(t);
    }

    sort(all(res),comp);

    // for(auto i : res) {
    //     for(auto j : i) {
    //         cout << j << " ";
    //     }
    //     cout << i.size();
    //     cout << endl;
    // }

    for(auto i : res[0]) {
        pq.push(0);
    }

    ll ans = 0;
    for(int i = 1; i < res.size(); i++) {
        ans++;
        ll t = pq.top();
        pq.pop();
        pq.push(t+1);
        pq.push(1);
        for(auto j : res[i]) {
            pq.push(0);
        }
        pq.pop();  //多推进了一个1
    }


    // ll ans = 0;
    ll ma = INT_MIN;
    // for(ll i = 1; i <= n; i++) {
    //     if(v[i]) continue;
    //     v[i] = 1;
    //     ans++;
    //     ll t = pq.top();
    //     pq.pop();
    //     pq.push(t+1);
    //     pq.push(1);
    //     // for(auto j : a[i]) {
    //     //     v[j] = 1;
    //     //     pq.push(0);
    //     // }
    //     // dfs(i);
    // }
    while(!pq.empty()) {
        // cout << pq.top() << endl;
        ma = max(ma,pq.top());
        pq.pop();
    }
    cout << ans << " " << ma << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}