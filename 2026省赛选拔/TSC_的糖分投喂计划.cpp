#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,  k;
    cin >> n >> k;
    // set<pair<int,int>> st;
    vector<int> v(n+1,-1);
    for(int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        v[a] = b;
        // pair<int,int> p;
        // // cin >> p.first >> p.second;
        // // st.insert(p);
        // v[p.first] = p.second;
    }

    // vector<int> ans(n+1);
    // for(int i = 1; i <= 1; i++) {
    //     queue<pair<int,int>> q;  // x, y
    //     q.push({i,0});
    //     while(!q.empty()) {
    //         auto [x,y] = q.front();
    //         q.pop();
    //         cerr << x << " " << y << endl;
    //         if(v[x]!=-1 && y==v[x]) {
    //             v[i] = abs(i-x)+y;
    //             break;
    //         }
    //         if(x>1 && y==0) q.push({x-1,y});
    //         if(v[x]!=-1) q.push({x,y+1});
    //         if(x<n && y==0) q.push({x+1,y});
    //     }
    // }
    // for(int i = 1; i <= n; i++){
    //     cout << ans[i] << " ";
    // }
    vector<int> ansa(n+1,1e9), ansb(n+1,1e9);
    vector<int> ta(n+1), tb(n+1);

    // 先定首位
    // 向右边找
    for(int i = 1; i <= n; i++) {
        if(v[i]==-1) continue;
        if(ansa[1] < i-1+v[i]) {
            ansa[1] = min(ansa[1],i-1+v[i]);
            ta[1] = i;
        }
    }
    // 向左边找
    for(int i = 1; i <= n; i++) {
        if(v[i]==-1) continue;
        if(ansb[1] < n-i+v[i]) {
            ansb[n] = min(ansb[n],n-i+v[i]);
            tb[n] = i;
        }
    }

    // 向右边找
    for(int i = 2; i <= n; i++) {
        if(ta[i-1] > i) {
            ansa[i] = ansa[i-1]-1;
        }else {
            ansa[i] = ansa[i-1]+(i-)
        }
        ansa[i] = ansa[i-1]-1;
    }
    // 向左边找;
    for(int i = 1; i < n; i++) {
        ansb[i] = ansb[i+1]-1;
    }
    for(int i =1; i <= n; i++) {
        cout << min(ansa[i],ansb[i]) << " ";
    }

}


int main() {
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}