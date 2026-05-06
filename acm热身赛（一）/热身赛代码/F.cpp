#include<bits/stdc++.h>
using namespace std;

using i64 = long long ;
using i128 = __int128_t;

constexpr int N = 1e6 + 1;

vector<int> pri;
bool not_prime[N];
int is_one[N], num[N];

void pre(int n) {
	for (int i = 2; i <= n; ++i) {
		if (!not_prime[i]) {
			pri.push_back(i);
			num[i] = 1;
			is_one[i] = i;
		}
		for (int pri_j : pri) {
			if (i * pri_j > n)
				break;
			not_prime[i * pri_j] = true;
			if (is_one[i] != pri_j) {
				is_one[i * pri_j] = 0;
			} else {
				is_one[i * pri_j] = is_one[i];
				num[i * pri_j] = num[i] + 1;
			}
			if (i % pri_j == 0) {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	pre(N - 1);
	int n;
	cin >> n;
	i64 res = 0;
	for (int i = 1; i <= n; i++) {
		i64 x;
		cin >> x;
		i64 v = sqrtl(x);
		if (v * v != x) {
			continue;
		}

		if (is_one[v] && !not_prime[2 * num[v] + 1]) {
			res += x;
		}
	}

	cout << res;
	return 0;
}