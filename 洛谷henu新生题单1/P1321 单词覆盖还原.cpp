/**
 * @brief:查找贴有boy和girl单词的字符串中两单词个数，注意两单词不重复，利用计算机可重复计算的优势
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int boy, girl;
    boy = girl = 0;
    for(int i = 0; i < s.size()-2; i++) {
        if(s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y'){
            boy++;
        }
    }
    for(int i = 0; i < s.size()-3; i++) {
        if(s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l'){
            girl++;
        }
}
    cout << boy << endl << girl <<endl;
    return 0;
}

//增加s长度，使两个查询放到一个循环中
#if 0
int main() {
    string s;
    cin >> s;
    int n = s.size();
    s += "....";
    int boy = 0, girl = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'b' || s[i+1] == 'o' || s[i+2] =='y') {
            boy++;
        }
        if(s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l') {
            girl++;
        }
    }

    printf("%d\n%d",boy,girl);

}

#endif