#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k+1);
    for(int i = 1; i <=k; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    cout << (a[k] * n)-(n*m) <<endl;
}