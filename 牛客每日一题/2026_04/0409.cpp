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
const int N = 1e6+5;
//url: https://www.nowcoder.com/practice/764c0b1b34d24122bd9ae75220e370a3?channelPut=tracker2
//  对于每一条路径，dfs的过程中加上概率即可
// 既有路径和权值，使用 pair 存
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> path(n+1);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        path[u].pb({v,w});
        // path[v].pb({u,w});
    }
    double res = 0;
    auto dfs = [&](auto&& self, int fu, int now, double val, double p) -> void {
        for(auto [i, w] : path[now]) {
            if(i==fu) continue;
            if(i==n) {
                val += w;
                p /= path[now].size();
                res += val*p;
                continue;
            }
            self(self,now,i,val+w,p/path[now].size());
        }
    };
    
    dfs(dfs,0,1,0,1);
    printf("%.2f",res);
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