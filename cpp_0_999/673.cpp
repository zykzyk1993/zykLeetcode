/*
 * 673. 最长递增子序列的个数
 * 题意：返回数组中最长递增子序列的个数
 * 难度：中等
 * 分类：dp
 * 算法：对于数组每个元素，保存以其结尾的最长递增子序列长度和个数，要么累加要么新增，对于max_len也是如此
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_len(n, 1); // 保存以i结尾的最长递增子序列长度
        vector<int> dp_cnt(n, 1); // 保存以i结尾的最长递增子序列个数
        int max_len = 1, res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[j] < nums[i]) { // 有可能转移
                    if (dp_len[j] + 1 > dp_len[i]) {
                        dp_len[i] = dp_len[j] + 1;
                        dp_cnt[i] = dp_cnt[j];
                    }
                    else if(dp_len[j] + 1 == dp_len[i]) {
                        dp_cnt[i] += dp_cnt[j];
                    }
                }
            }
            if (dp_len[i] > max_len) {
                max_len = dp_len[i];
                res = dp_cnt[i];
            }
            else if (dp_len[i] == max_len) {
                res += dp_cnt[i];
            }
        }
        return res;
    }
};
