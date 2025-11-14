/**
 * @brief: 推算字母后移n位后的结果
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    for(char& ch : s) {
        cout << char((ch - 'a' + n) % 26 + 'a');
    }

    return 0;
}