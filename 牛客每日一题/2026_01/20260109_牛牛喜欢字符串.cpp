//需要改到相同的字符串，首先想要改到什么字符串，有两种情况：已有的子串或则新的子串；
//如果已有字串，我首先想到暴力计算转化为每个子串的操作次数再取最佳；复杂度太高放弃
//如果是新串，思考应该满足什么条件，不可能是父串中没有的字符组成，则想到新串的每一位一定是各个子串中每一位上出现最多次数的字符！
//所以我们只需要找到每一位上出现最多次数的字母的出现次数，遍历统计即可
//首先想到每次遍历一个位置，要n*k 次，想减少时间复杂度，创建一个新的数组存每一位上最值，用空间换时间；
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "0" + s;  //使下标从1开始；
    vector<vector<int> > a(k+1, vector<int>(26)); // 存储每个位置上每个字母出现次数
    vector<int> maxn(k+1, INT_MIN); // 每个位置上的最大次数；

    for(int i = 1; i <= n; i += k) { //第 i 个字符
        for(int p = 1; p <= k; p++) {  //当前字串的第p个字符；
            maxn[p] = max(maxn[p], ++a[p][s[i+p-1]-'a']);
        }
    }
    int ct = 0;
    for(int i = 1; i <= k; i++) {
        // cout << maxn[i] << "\n";
        ct += maxn[i];
    }

    int ans = n-ct;
    cout << ans << endl;
}