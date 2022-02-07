/*
 * 45. 跳跃游戏 II
 * 题意：格子上为可以向前跳的步数，求到最后一格的最短步数
 * 难度：中等
 * 分类：贪心
 * 算法：每次记录下一次可以到达的最远距离，当i到达当前次最远的时候，step+1
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};
