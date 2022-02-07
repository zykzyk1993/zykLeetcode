/*
* 27. 移除元素
* 题意：给定有序数组，原地删除和给定元素相等的元素
* 难度：简单
* 分类：数组
* 算法：和26题解法一致
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), dup_cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val){
                dup_cnt ++;
            }
            else
                nums[i-dup_cnt] = nums[i];
        }
        return n-dup_cnt;
    }
};
