/*
 * 398. 随机数索引
 * 题意：给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引
 * 难度：中等
 * 分类：哈希表
 * 算法：蓄水池抽样，遇到target则以1/n的概率替换索引
 */
class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int n = 0, res = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if (nums[i] == target) {
                n++;
                if(rand() % n == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
