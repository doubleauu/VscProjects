///子区间数量
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int& num : nums){
        cin >> num; //读取数据，注意地址引用，增强for循环使用的是容器副本
    }

    int count = 0; //子区间数量记录
    for(int i = 0; i < n; i++) {
        if(nums[i] == k) {
            count++;  //查看首位是否符合子区间要求
            for(int a = i + 1; a < n; a++){  //检查后续是否有 0
                if(nums[a] == 0) {
                    count++;
                }else break;
            }
        }
        else{
            int temp = nums[i]; //存储求区间和的中间结果
            int j = i + 1;
            while(j < n){
                temp += nums[j];
                if(temp == k) count++; //检查当前区间和结果
                j++; 
            }
        }
    }

    cout << count << endl;

}