/**
 * @brief: 读取数组只输出质数（素数）（只能被1和他本身整除，即取余为0）
 */
#include <bits/stdc++.h>
using namespace std;

bool isPrime() {}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for(int i : nums) {
        if(i <= 1) continue;                 //注意素数需要大于1！！
        bool isPrime = true;
        for(int j = 2; j <= sqrt(i); j++) {  //注意从2开始除
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime) cout << i << ' ' ;
    }

}