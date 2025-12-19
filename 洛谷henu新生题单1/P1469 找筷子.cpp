/**
 * @brief:使用位异或操作符，找到落单的筷子长度
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);  //使用c语言风格，反应更快
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        ans ^= a;  //异或运算符满足交换律和结合律
    }
    printf("%d\n",ans);
    return 0;
}