  
/*
 * 448. 找到所有数组中消失的数字
 * 给定数字范围 [1, n] 的数组，找到所有在 [1, n] 范围之间没有出现在数组中的数字，不使用额外空间
 * 难度：简单
 * 分类：数组
 * 算法：每次出现一个数字，对应位加上n，最后检查，即可不使用额外空间
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return nums;
        for(int i=0;i<nums.size();i++)
        {
            int index=(nums[i]-1)%nums.size();
            nums[index]+=nums.size();
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=nums.size())
                res.push_back(i+1);
        }
        return res;
    }
};
