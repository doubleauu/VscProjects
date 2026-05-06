// 拓扑排序模板，要理解其中的思路，度与前置任务的概念；
// 离散数学中出度与入度；
#include <bits/stdc++.h>
using namespace std;

struct M {
    int a = 0;  // 前置任务的数量 
    vector<int> b;  // 存后置任务节点 
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<M> arr(n+1);
    for(int i = 1; i <= m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        arr[t2].a++;
        arr[t1].b.push_back(t2);
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(arr[i].a == 0) q.push(i);
    }

    vector<int> ans; // 假定可以排序成功，暂存答案；

    while(!q.empty()) {
        int t = q.front();  //记录当前任务索引
        ans.push_back(t);
        q.pop();

        for(int i : arr[t].b) {
            arr[i].a--;
            if(arr[i].a == 0) q.push(i);
        }
        
    }
    
    if(ans.size() != n){
        cout << -1 << "\n";
        return 0;
    } 
    for(int i = 0; i < n; i++) {
        cout << ans[i];
        if(i != n-1) cout << " ";  // 注意最后一个数不能输出空格；
    }
}