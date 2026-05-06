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
url: https://codeforces.com/gym/106507/problem/B
题目：给出一个首尾相连的连续环状序列，将其分割为尽量少的完美序列（任意相邻不相同，包括首尾）
很容易想到，相邻元素相同必须要做切割
我们使用stack方便判断相邻元素相同的情况
为了使花环数量尽量的少，我们每次编花环使其尽可能地长
因为花环是首尾相连的，所以我们每次连接要特殊判断首尾出：判断下一个元素能否编入：
1. 新元素不能与栈顶相同
2. 如果下一个元素不能编入，还要判断上一个元素能否保留（是否与栈底相同，参考样例五）

参考样例三：
为了少切一刀，我们要尽可能把某一组相同的元素放在两端，这样当中间做过分割的话这一组元素就跟着分开；
可能可以少切一刀，但是如果只有这一组相同元素就不能省了（参考样例4）
~~感觉cf给的样例很有一般性，很好用~~
*/

void solve() {
	int n;
    cin >> n;
    deque<int> a(n+2);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto past = [&](int i) {
        return a[(i-1+n)%n];
    };
    auto next = [&](int i ) {
        return a[(i+1+n)%n];
    };

    // 尽量使两端的元素相同，可以少切一刀
    deque<int> b;
    a[n+1] = a[1];  // 形成首尾相连
    for(int i = 1; i <= n;i++) {
        if(a[i] == a[i+1]) {
            for(int j = i+1; j <= n; j++) b.pb(a[j]);
            for(int j = 1; j <= i; j++) b.pb(a[j]);
            break;
        }

    }
    if(b.size()==0) {
        cout << 1 << endl;
        return;
    }
    int ans = 0;
    while(!b.empty()) {
        stack<int> st;
        int ct = 0;
        for(auto i : b) {
            if(!st.empty() && i==st.top()) {
                if(ct > 1 && st.top()==b.front()) {
                    st.pop();
                    ct--;
                }
                break;
            }
            st.push(i);
            ct++;
        }
        if(st.size()>1 && b.front()==st.top()) ct--;
        while(ct--) b.pop_front();
        ans++;
    }
    cout << ans << endl;
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