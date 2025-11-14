/**
 * @brief: 输出指定范围内的回文质数
 */
#include <bits/stdc++.h>
using namespace std;

 //封装判断是否回文的函数
 bool isPalindrome(int n) {
    if(n < 0) return false;
    int temp = n;
    int a = 0;  //储存反转后的数字
    while(n != 0){
        int i = n % 10;
        a = a * 10 + i;
        n /= 10;    // '/=' 去掉末位，'%10'获取末位
    }
    return a == temp;
}

 //封装判断是否质数
 bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
 }

 int main() {
    int a, b;
    cin >> a >> b;

    for(int i = a; i <= b; i++)  {   //虽说只有奇数才能是质数，但是不知起始如何，还是要暴力枚举
        if(isPalindrome(i) && isPrime(i)) cout << i << endl;
    }
    
    return 0;
 }