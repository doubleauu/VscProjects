//利用hash值将字符串之间的比较转化为数字之间的比较；
#include <bits/stdc++.h>
using namespace std;
#define B 271
#define ull unsigned long long

struct M {
    int len;
    // vector<string> s;  // 注意下标是从零开始；
    vector<ull> h;   // 注意下标是从零开始；
};

ull getHash(string s) {
    ull t = 0;
    for(int i = 0; i < s.size(); i++) {
        t = t * B + s[i];
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<M> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].len;
        for(int j = 1; j <= a[i].len; j++) {
            string t;
            cin >> t;
            // a[i].s.push_back(t);
            a[i].h.push_back(getHash(t));
        }
    }

    int m; 
    cin >> m;
    for(int i = 1; i <= m; i++) {
        string t;
        cin >> t;
        ull ha = getHash(t);
        for(int j = 1; j <= n; j++) {  // 第j 篇文章；
            for(int k = 0; k < a[j].h.size(); k++) {
                if(ha == a[j].h[k]) {
                    cout << j << " ";
                    break;
                }
            }
        }
        cout << "\n";
    }

    
}