#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *b = new int[n+1];
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(i==1) {
            b[i] = a;
            ans = b[i];
        }else {
            b[i] = a + b[i-1] >= a ? a+b[i-1] : a;
            ans = ans > b[i] ? ans : b[i];
        }
    }
    cout << ans;
}