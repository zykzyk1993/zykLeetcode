/*
* 26. 删除有序数组中的重复项
* 题意：给定有序数组，原地删除重复元素
* 难度：简单
* 分类：数组
* 算法：记录重复元素个数，向前移动
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), dup_cnt = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]){
                dup_cnt ++;
            }
            else
                nums[i-dup_cnt] = nums[i];
        }
        return n-dup_cnt;
    }
};
