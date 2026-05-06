#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
/*
url: https://codeforces.com/contest/2200/problem/C
拉丁字母就是 26 个英文字母
可以对元素进行操作的条件是两个元素相同且之间都是 *
容易发现第一次操作一定是两个相邻且相同的元素；
后续操作将在其两端进行
进一步我们可以想到将更改后的元素都删除，因为操作的条件是中间全是 *,和相邻是等效的；
相邻相同抵消，联想到括号序列问题
使用 栈 操作
*/
void solve() {
	int n;
    cin >> n;
    stack<char> st;
    while(n--) {
        char c;
        cin >> c;
        if(st.empty()) {
            st.push(c);
            continue;
        }
        if(c==st.top()) st.pop();
        else st.push(c);
    }
    if(st.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}