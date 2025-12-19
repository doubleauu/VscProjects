/**
 * @brief: 输出每个子串的最值；
 * @details: 使用单调队列，分两次操作，先找每次的最小值，再找每次的最大值
 */
#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  //提速
    }
    
    //求最小值，递增队列，使用空间避免命名冲突
    {
        deque<int> dq;
        deque<int> site;  //用于记录下标，方便过期后弹出
        int l = 0, r = 0;
        while(r < n) {           //外层循环实现窗口滑动
            while(r <= l+k-1) {  //内层循环形成窗口，主要是便于遍历第一个窗口
                while(!dq.empty() && a[r] < dq.back()) {
                    dq.pop_back();
                    site.pop_back();
                }
                dq.push_back(a[r]);
                site.push_back(r);
                r++;
            }
            cout << dq.front() << " ";
            if(site.front() == l) {
                site.pop_front();
                dq.pop_front();
            }
            l++;
        }
    }

    cout << endl;

    //求最大值，递减队列；
    {
        deque<int> dq;
        deque<int> site;
        int l = 0, r = 0;
        while(r < n) {
            while(r <= l+k-1) {
                while(!dq.empty() && a[r] > dq.back()) {
                    dq.pop_back();
                    site.pop_back();
                }
                dq.push_back(a[r]);
                site.push_back(r);
                r++;
            }
            cout << dq.front() << " ";
            if(site.front() == l) {
                site.pop_front();
                dq.pop_front();
            }
            l++;
        }
    }

}