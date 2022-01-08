/*
 * 645. 错误的集合
 * 题意：其中一个数被复制成了另一个数，求出来两个错误的数字，原地解决
 * 难度：简单
 * 分类：数组
 * 算法：采用负数索引标记的方法，遇到一个数将其索引处变为负数，过程中判断重复，最终留下的正数为重复数字
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++) {
            int idx = nums[i] > 0?nums[i]:-nums[i];
            if(nums[idx - 1] < 0) {
                res.push_back(idx);
            }
            else {
                nums[idx - 1] = -nums[idx - 1];
            }
        }
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
