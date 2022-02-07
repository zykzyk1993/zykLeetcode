/*
 * 665. 非递减数列
 * 题意：判断最多改变一个元素的情况下，能否变成非递减序列
 * 难度：中等
 * 分类：贪心 模拟
 * 算法：当出现逆序对时，尝试分别修改这两个元素中的一个
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool change = false;
        int n = nums.size();
        if (n < 3) return true;
        for(int i = 1; i < n; i++){
            if(nums[i] >= nums[i-1])
                continue;
            if (change)
                return false;
            if (i == n-1 || nums[i+1] >= nums[i-1]){
                change = true;
                continue;
            }
            if (i == 1 || nums[i-2] <= nums[i]){
                change = true;
                continue;
            }
            return false;
        }
        return true;
    }
};
