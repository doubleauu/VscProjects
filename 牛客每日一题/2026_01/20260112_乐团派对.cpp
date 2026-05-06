#include <bits/stdc++.h>
using namespace std;

int main() {   
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    if(a.back() > n) {  //保证每个人都要有乐队，如果最后一个人无法分配到乐队中：输出 -1；
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 1;   // 最后一位分一组；然后再从前往后排；保证优先分配能力值低的形成队伍使得数量最多，有保证了每一位成员都能组成队伍（散落的放到最后一组一定符合情况）
    bool failed = false;  // 中间散落的放到最后即可；
    for(int i = 1; i <= n - a.back(); i++) {
        bool failed = true;
        int t = 0;
        for(int j = i; j <= n - a.back(); j++) {
            t++;
            if(t == a[j]) { 
                ans++;
                i = j;
                failed = false;
                break;
            }
        }
        if(failed) break;
    }
    
    cout << ans << "\n";


}