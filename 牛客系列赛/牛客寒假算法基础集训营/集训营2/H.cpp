// Problem: 权值计算
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/H
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        // prev[i]: a[i] 在 i 之前最近一次出现的位置；没有则为 0
        unordered_map<int, int> last;
        vector<int> prev(n + 1, 0);
        prev[0] = 0;
        for (int i = 1; i <= n; ++i) {
            auto it = last.find(a[i]);
            prev[i] = (it == last.end() ? 0 : it->second);
            last[a[i]] = i;
        }

        // 按“首次出现位置 j”的贡献累加
        // 每个 j 的贡献： (j - prev[j]) * tri(n - j + 1)
        // tri(m) = m * (m + 1) / 2
        long long ans = 0;
        for (int j = 1; j <= n; ++j) {
            long long leftChoices = j - prev[j];
            long long m = n - j + 1;
            long long rightSum = m * (m + 1) / 2;
            ans += leftChoices * rightSum;
        }

        cout << ans << endl;
    }
    return 0;
}