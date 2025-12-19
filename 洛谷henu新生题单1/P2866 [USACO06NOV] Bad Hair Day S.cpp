//使用单调队列做，感觉deque能同时代替stack和queue
/**
 * @details: 类似求区间最大值，那就维护一个递减的单调队列
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

deque<int> dq;
deque<int> site;
ll ans;

int main() {
    int N;
    cin >> N;
    vector<int> a(N+2);  //缓冲区避免越界
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    dq.push_back(a[1]);
    
    for(int i = 2; i <= N; i++) {
        while(!dq.empty() && a[i] >= dq.back()) {  //因为相等也会遮蔽视线，所以当相等时也要pop推出
            dq.pop_back();
        }
        ans += dq.size(); //每当要进入一个新的牛，那么队列中的牛都可以多看到一头，只需要求总数而不需要求每个牛能看到多少，所以直接总数加size即可实现每头牛看到数量加一！
        dq.push_back(a[i]);
    }
    cout << ans;
}