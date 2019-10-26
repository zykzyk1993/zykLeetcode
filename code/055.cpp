/*
 * 55. 跳跃游戏
 * 判断你是否能够到达最后一个位置
 * 难度：中等
 * 分类：数组 贪心
 * 算法：每次更新能到达的最右边
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return true;
        int right=nums[0];
        for(int i=0;i<n;i++){
            if(i>right)return false;
            right=max(right,i+nums[i]);
        }
        return true;
    }
};
