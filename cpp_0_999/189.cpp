/*
 * 189. 轮转数组
 * 题意：数组向左移K位
 * 难度：简单
 * 分类：数组
 * 算法：前后两部分翻转，然后整体翻转
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k % n;
        if (k == n){
            return;
        }
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
