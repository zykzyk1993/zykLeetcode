/*
 * 1. 两数之和
 * 题意：返回数组中和为给定数的下标
 * 难度：简单
 * 分类：哈希表
 * 算法：题目说明了数组中一定有解，且解唯一，所以用哈希表记录已遍历的元素即可
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(m.count(target-nums[i])){
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};
