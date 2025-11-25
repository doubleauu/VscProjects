#include<bits/stdc++.h>
using namespace std;

using i64 = long long ;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> f(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}

	int mx = 0, num = 0;
	for (int i = 2; i <= n; i++) {
		if (f[i] >= mx && f[i] > 0) {
			mx = f[i];
			num = i;
		}
	}

	cout << n - (mx != 0) << '\n';
	f[1] += mx;
	for (int i = 1; i <= n; i++) {
		if (i == num) {
			continue;
		}
		cout << f[i] << " ";
	}
	return 0;
}