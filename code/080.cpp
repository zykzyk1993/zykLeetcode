/*
 * 80. 删除有序数组中的重复项 II
 * 题意：删除数组项使得每个元素最多出现两次
 * 难度：中等
 * 分类：数组 双指针
 * 算法：和前题不同，会产生覆盖为1时结果出错的问题，必须记录上一个位置是否是相同的，然后向前覆盖
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), dup = 0, is_dup = false;
        for(int i = 1; i < n; i++){
            if(nums[i]==nums[i-1]){
                if(is_dup){
                    dup++;
                }else{
                    nums[i-dup] = nums[i];
                }
                is_dup = true;
            }
            else{
                is_dup = false;
                nums[i-dup] = nums[i];
            }
        }
        return n-dup;
    }
};
