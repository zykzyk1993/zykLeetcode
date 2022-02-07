/*
 * 41. 缺失的第一个正数
 * 题意：原地找出 数组内缺失的第一个正数 默认是1~n，都存在就返回n+1
 * 难度：困难
 * 分类：数组
 * 算法：基于交换的算法，如果在1~n之外，则跳过，否则交换到其给定位置，如果已经位置正确，或交换后还是原来的数，则跳过，最后遍历得到第一个数就是结果
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            if(nums[i] == i + 1){
                continue;
            }
            if(nums[i] > n || nums[i] <= 0){
                continue;
            }
            if(nums[nums[i] - 1] == nums[i]){
                continue;
            }
            swap(nums[i], nums[nums[i] - 1]);
            i --;
        }
        for(int i = 0; i < n; i ++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
};
