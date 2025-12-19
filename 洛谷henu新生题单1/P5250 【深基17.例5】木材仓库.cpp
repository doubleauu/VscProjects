/**
 * @brief: 木材仓库管理，存入和取出操作，输出取出操作时的最优值，或存入时的冲突信息
 * @details: 使用set结构
 */
#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
    int n, op, len;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> op >> len;
        if(op == 1) {
            if(s.find(len) != s.end()) {
                cout << "Already Exist" << endl;
            }else {
                s.insert(len);
            }
        }else {
            if(s.empty()) cout << "Empty" <<endl;
            else{
                set<int>::iterator it = s.lower_bound(len);
                // set<int>::iterator p = it; p--; //不合法，p--可能会发生未定义行为（p为begin()）时
                set<int>::iterator p = it;
                //防止越界访问：
                if(it == s.begin()) p = it;
                else if(it == s.end()) p = --it;  //合法，it和p都将指向最后一个元素
                else p--;
                if(len - *p <= *it - len) {
                    cout << *p << endl;
                    s.erase(p);
                }else {
                    cout << *it << endl;
                    s.erase(it);
                }

            }
        }
    }
    
}