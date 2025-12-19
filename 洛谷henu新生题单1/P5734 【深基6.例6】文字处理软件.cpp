/**
 * @brief: 简单的文字处理软件，包括四种操作
 */
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        int m; //选择操作序号
        cin >> m;
        if(m == 1){             //后接操作
            string str;
            cin >> str;
            s += str;
            cout << s << endl;
        }else if(m == 2) {      //保留从a起之后的b个字符
            int a, b;
            cin >> a >> b;
            s.erase(0, a);      //erase操作是左闭右开，第二个参数是长度而不是结束位置！
            s.erase(b, s.size());
            cout << s << endl;
        }else if(m == 3) {      //插入片段
            int a;
            string str;
            cin >> a >> str;
            s.insert(a, str);
            cout << s << endl;
        }else if(m == 4) {      //查找子串，没有返回-1
            string str;
            cin >> str;
            size_t pos = s.find(str); //返回类型未size_t,无符号整数类型
            if (pos == string::npos)  //判定未找到行为
                cout << -1 << endl;
            else
                cout << pos << endl;
        }
    }
}