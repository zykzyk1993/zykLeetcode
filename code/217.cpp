/*
 * 217. 存在重复元素
 * 题意：判断数组中是否有重复元素
 * 难度：简单
 * 分类：哈希表
 * 算法：哈希表
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &num:nums){
            if(s.count(num) > 0)
                return true;
            s.insert(num);
        }
        return false;
    }
};
