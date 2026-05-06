#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, x;
    cin >> a >> b >> x;
    int tx = x/2;
    if(a == 0 || b == 0) {
        cout << -1 << "\n";
        return 0;
    }
    if((a-tx)%2 != 0 || (b-tx)%2 !=0) {
        cout << -1 << "\n";
        return 0;
    }
    if(min(a,b) < tx) {
        cout << -1 << "\n";
        return 0;
    }
    string ans = "";
    for(int i = 0; i < a-tx; i++) {
        ans.append("0");
    }
    for(int i = 0; i < tx; i++) {
        ans.append("10");
    }
    for(int i = 0; i < b-tx; i++) {
        ans.append("1");
    }
    cout << ans <<"\n";
    return 0;
}
