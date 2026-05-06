// 一看到查询我就想跑前缀和；
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];

    }
    while(q--) {
        int t;
        cin >> t;
        // 因为题目是从第0 秒开始算的，我们要从一开始计算，进行一个偏移；
        // 使用stl函数计算询问时间点属于那个音符的区间；
        auto i = lower_bound(pre.begin()+1, pre.end(), t+1);
        cout << i-pre.begin() << endl;
    }
}