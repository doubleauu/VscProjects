// 模仿素数筛思路，利用前面的小元素 ”筛掉“ 后面的大元素；
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, a1, m;
    cin >> n >> a1 >> m;
    vector<int> a(n+1), b(n+1);
    a[1] = a1;
    for(int i = 2; i <= n; i++) {
        a[i] = (a[i-1] + 7*i) % m;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j+=i) {
            b[j] += a[i];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans ^= b[i];
    cout << ans;
}
