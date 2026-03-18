#include<bits/stdc++.h>
using namespace std;

using i64 = long long ;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	i64 n, m, k;
	cin >> n >> m >> k;
	vector<i64> f(k + 1);
	for (int i = 1; i <= k; i++) {
		cin >> f[i];
	}

	cout << (*max_element(f.begin(), f.end()) - m) * n;
	return 0;
}