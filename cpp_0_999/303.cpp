/*
 * 303. 区域和检索 - 数组不可变
 * 题意：随意检索两个索引之间的数字之和
 * 难度：简单
 * 分类：数组 前缀和
 * 算法：记录前缀和，每次相减，注意是right+1
 */

class NumArray {
public:
    vector<int> prefix_sum = {0};
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(auto &num:nums){
            sum += num;
            prefix_sum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
