#include<bits/stdc++.h>
using namespace std;

using i64 = long long ;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n);
	for (auto& x : a) {
		cin >> x;
	}

	sort(a.begin(), a.end());

	i64 res = 0;
	for (int i = 0; i < n - 1; i++) {
		res += a[i] / k + (a[i] % k != 0);
		a[i + 1] += a[i];
	}

	cout << res;
	return 0;
}