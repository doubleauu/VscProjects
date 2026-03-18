#include<bits/stdc++.h>
using namespace std;

using i64 = long long ;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	cout << "Average = " << m / n + (m % n != 0);
	return 0;
}