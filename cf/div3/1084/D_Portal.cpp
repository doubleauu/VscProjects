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
/*
url: https://codeforces.com/contest/2200/problem/D
观察样例发现两个传送们之间的元素在其作用下变成一个环状
我们呢可以任选起点
两个传送门两端的元素顺序恒定，将传送门及之间的元素视为一个内部块
则我们可以将该个块放在任何一个位置做切割
两部分互不干扰（即传送门之间元素不能进入两端，反之亦然）
需要寻找字典序最小，则内部一定是最小为起点
然后考虑放在哪里切割外部序列；
字典序是从前往后比，我们就可以把内部块放到刚好比内部起点小的元素后面
如果没有就放首位
注意如果外部数组中前端有多个相同的值恰好是内部块的最小值
我们要将内部块放到最后一个相同值后面，因为内部块起点之后的元素一定是大于等于起点的；
*/
void solve() {
	int n, x, y;
    cin >> n >> x >> y;
    vector<int> wai, nei;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if(i<=x) wai.pb(t);
        else if(i>y) wai.pb(t);
        else nei.pb(t);
    }

    if(nei.empty()) {
       for(auto i : wai) cout << i << " ";
       cout << endl;
       return; 
    }
    
    int pos = min_element(all(nei)) - nei.begin();
    vector<int> res(nei.begin()+pos,nei.end());
    for(int i = 0; i < pos; i++) {
        res.pb(nei[i]);
    }
    int mi = nei[pos];
    bool has = 0; // 判断内部块是否已经输出
    
    // 下标访问前一定要判空
    if(wai.empty()) {
        for(auto i : res) cout << i << " ";
        cout << endl;
        return;
    }
    if(wai[0] > mi) {
        for(auto i : res) cout << i << " ";
        has = 1;
    }
    for(int i = 0; i < wai.size()-1; i++) {
        cout << wai[i] << " ";
        if(!has && wai[i]<=mi && wai[i+1]>mi) {
            for(auto i : res) cout << i << " ";
            has = 1;
        }
    }

    // 单独处理最后一个元素，防止 +1 越界
    cout << wai.back() << " ";
    if(!has) {
        for(auto i : res) cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
    