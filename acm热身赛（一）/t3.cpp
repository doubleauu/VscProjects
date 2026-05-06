#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 1; i < n; i++) {
        while(a[i] != 0) {
            if(a[i] >= k) {
                a[i] -= k;
                a[i+1] += k;
                ans++;
            }else {
                a[i+1] += a[i];
                a[i] = 0;
                ans++;
            }
        }
    }
    cout << ans;

}