/**
 * @brief: 判断括号序列是否合法。
 * @details: 第一个反括号前面必定是最后一个正括号，可以使用栈结构，后进先出
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<char> a;
    char ch;
    while(cin >> ch) {  //持续输入
        if(ch == '(' || ch == '{' || ch == '[') {
            a.push(ch);
        }else {
            if(a.empty() ) {  //防止首位即是反括号导致栈越界；
                cout << "No";
                return 0;
            }
            char temp = a.top();
            if(temp == '(' && ch ==')' || temp == '[' && ch ==']' || temp == '{' && ch =='}') {
                a.pop();
            }else {
                cout << "No" <<endl;
                return 0;
            }
        }
    }
    if(!(a.empty())) {  //最后栈不为空，说明有未抵消的正括号！
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}