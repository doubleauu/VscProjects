/**
 * @brief: 二分查找
 */
#include <bits/stdc++.h>
using namespace std;

//二分查找，数组递增，始终保持左闭右闭的区间
int binarySearch(const vector<int>& nums, int target) {  //注意使用常量引用传递，避免复制开销
    int left = 0;
    int right = nums.size() - 1;
    int ans = -2;     //处理需要返回-1的情况
    while(left <= right) {
        int mid = left + ((right - left)/2);

        //使用if-else分支，而不用多个if判断
        if(nums[mid] > target) {
            right = mid - 1;
        }else if(nums[mid] < target) {
            left = mid + 1;
        }else {
            ans = mid;
            right = mid - 1; //继续向左查询，使返回第一次出现位置
        }
        
    }
    return ans + 1;   //需要返回编号而不是下标，所以求出ans为下标时返回ans+1
}

int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    vector<int> nums(n);
    for(int& i : nums) {
        scanf("%d", &i);
    }
    for(int i = 0; i < m; i++) {
        int target;
        scanf("%d",&target);
        printf("%d ", binarySearch(nums,target));
    }
}