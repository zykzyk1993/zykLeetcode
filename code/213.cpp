/*
 * 213. 打家劫舍 II
 * 题意：相邻的房屋不能同时打劫，且首尾房屋相连
 * 难度：中等
 * 分类：dp
 * 算法：从1到n-1打劫一次，从2到n打劫一次，取最大值
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        int rob = nums[0], not_rob = 0;
        for(int i=1; i<n-1;i++){
            int prev_not_rob = not_rob, prev_rob = rob;
            rob = not_rob + nums[i];
            not_rob = max(prev_not_rob, prev_rob);
        }
        int ans = max(rob, not_rob);
        rob = nums[1], not_rob = 0;
        for(int i=2; i<n;i++){
            int prev_not_rob = not_rob, prev_rob = rob;
            rob = not_rob + nums[i];
            not_rob = max(prev_not_rob, prev_rob);
        }
        ans = max(ans, max(rob, not_rob));
        return ans;
    }
};
