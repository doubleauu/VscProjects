//三角统计中有频繁的查询，可以使用set数据结构；
//如何遍历set和欧几里得求最大公约数的条件；
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {  // 注意条件是a > b;
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<set<int>> a(n+1);
        for(int i = 1; i <= m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            a[t1].insert(t2);
            a[t2].insert(t1);
        }
        int ctb = 0, ctj = 0;

        //以i为中间点统计边的数量，以（i, a[i]中的元素)为边统计角的数量
        for(int i = 1; i <= n; i++) {
            int size = a[i].size();
            if(size) ctb += (size)*(size-1)/2;

            auto j = a[i].begin();
            for(; j != a[i].end(); j++) {  //
                if(*j <= i) continue;
                auto k = a[*j].begin();
                for(; k != a[*j].end(); k++) {
                    if(*k == i) continue;
                    if(a[*k].find(i) != a[*k].end()) ctj++;
                }
            }
        }
        if(ctj == 0) cout << 0 << "/" << 1 << "\n";
        else if(ctj > ctb) {
            int t  = gcd(ctj, ctb);
            cout << ctj/t << "/" << ctb/t << "\n";
        }
        else {
            int t  = gcd(ctb, ctj);
            cout << ctj/t << "/" << ctb/t << "\n";
        }

    }
}