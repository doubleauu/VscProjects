/**
 * @brief: 给出一个长度为 n 的序列 a，选出其中连续且非空的一段使得这段和最大。
 * @details: 线性动态规划；
 * @param: b[i]: 表示第i个数所在有效序列的元素和，即以第i个元素结尾的最大连续字段和；
 * 优化：可以每次读取a数组值不用数组，减少空间使用；
 */
#include <bits/stdc++.h>
using namespace std;

int ans = INT_MIN;

int main() {
    int n;
    cin >> n;
    int *a = new int[n+1];  
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int *b = new int[n+1];
    b[1] = a[1];
    ans = b[1];
    for(int i = 2; i <= n; i++) {
        int temp = a[i] + b[i-1];
        if(a[i] > temp) {
            b[i] = a[i];
        }else {
            b[i] = temp;
        }
        ans = ans > b[i] ? ans : b[i];
    }
    cout << ans << endl;
}