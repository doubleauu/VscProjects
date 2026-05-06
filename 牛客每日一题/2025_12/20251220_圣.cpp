
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        int t = 0;;
        // for(int i = 1; i <= n; i++) {
        //     int t = 0;
        //     for(int j = 1; j <= n; j++) {
        //         t |= (a[i]&a[j]);        //内层循环的结果参考分配律提取公共项，结果还是ai
        //     }
        //     ans ^= t;
        // }
        for(int i = 1; i <= n; i++) {
            cin >> t;
            ans ^= t;
        }
        
        cout << ans << endl;
    }
}