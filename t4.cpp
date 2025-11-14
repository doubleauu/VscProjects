#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;   //读取数组内容
    }
    
    long long sum = 0; //记录总和；
    for(int i = 0; i < n; i++) {
        sum += nums[i]; //首先加上首位，后面再计算区间乘积

        int j = i + 1;
        long long temp = nums[i]; //存储连乘时的中间结果；
        while(j < n){ //开始计算区间的乘积
            temp *= nums[j];
            sum += temp;
            j++; //计算加上下一位的连乘
        }
    }
    
    cout << sum << endl;
}