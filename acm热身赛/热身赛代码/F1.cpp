#include<bits/stdc++.h>
using namespace std;

using i64 = long long ;
using i128 = __int128_t;

constexpr i64 MAXN = 1e12;
constexpr i64 N = 1e6 + 1;

vector<int> pri;
bool not_prime[N];

void pre(int n) {
	for (int i = 2; i <= n; ++i) {
		if (!not_prime[i]) {
			pri.push_back(i);
		}
		for (int pri_j : pri) {
			if (i * pri_j > n)
				break;
			not_prime[i * pri_j] = true;
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

	set<i64> st;
	for (const auto& x : pri) {
		i64 now = x ;
		int cnt = 1;
		while (now <= MAXN) {
			now *= x;
			cnt++;
			if (!not_prime[cnt + 1]) {
				st.insert(now);
			}
		}
	}

	cout << st.size() << "\n";
	i64 res = 0;
	for (int i = 1; i <= n; i++) {
		i64 x;
		cin >> x;
		if (st.find(x) != st.end()) {
			res += x;
		}
	}

	cout << res;
	return 0;
}