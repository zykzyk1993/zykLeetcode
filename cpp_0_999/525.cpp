/*
 * 525. 连续数组
 * 题意：找到由相同0和1数量组成的最长子数组
 * 难度：中等
 * 分类：哈希表 前缀和
 * 算法：用哈希表记录每一个balance最先出现的位置，然后判断找相同的balance即可
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int balance = 0, ans = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for(int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 1) {
                balance ++;
            }
            else {
                balance --;
            }
            if (m.count(balance)) {
                ans = max(ans, i - m[balance]);
            }
            else {
                m[balance] = i;
            }
        }
        return ans;
    }
};
