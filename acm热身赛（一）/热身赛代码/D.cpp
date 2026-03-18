#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

vector<i64> fac;

void dfs(i64 res, int num) {
    cout << res;
    if (res == fac.back()) {
        return;
    }

    cout << " = (";
    dfs(res / fac[num], num + 1);
    cout << ") * " << fac[num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 x;
    cin >> x;

    i64 t = x;
    for (i64 i = 2; i * i <= t; i++) {
        while (t % i == 0) {
            fac.push_back(i);
            t /= i;
        }
    }

    if (t > 1) {
        fac.push_back(t);
    }

    dfs(x, 0);
    return 0;
}