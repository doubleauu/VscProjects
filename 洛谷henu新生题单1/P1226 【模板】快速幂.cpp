/**
 * @brief: 求幂然后取模
 */
#include <bits/stdc++.h>
using namespace std;

#if 0
//普通算法，复杂度o(n2)
int main() {
    int a, b, p;
    cin >> a >> b >> p;
    long long ans = 1;
    for(int i = 0; i < b; i++) {
        ans = (1LL * ans * a) % p;  //每次乘法运算后取模防止溢出
    }

    cout << a <<'^'<< b <<" mod "<< p <<" = "<< ans; 
}
#endif

//快速幂算法，复杂度o(log2(n))
int main() {
    int a, b, p;
    cin >> a >> b >> p;
    int btemp = b;

    int base = a;
    int ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (1LL * ans % p) * base % p;  //1LL只是暂时把ans提升到ll，最终结果还是看变量声明，此处防止int溢出，还是要取余，还有一种方法就是直接用long long类型！
        }
        base = (1LL * base * base) % p;  //取余运算符支持所有整型，但不支持浮点数等类型
        b >>= 1;
    }
    cout << a << '^' << btemp << " mod " << p << "=" << ans <<endl;
    return 0;
}