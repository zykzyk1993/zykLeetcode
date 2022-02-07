/*
 * 698. 划分为k个相等的子集
 * 题意：找出是否有可能把这个数组分成 k 个非空子集，其总和都相等
 * 难度：中等
 * 分类：dfs
 * 算法：计算出划分后的sum，然后判断是否可以dfs一共k次
 */
class Solution {
public:
    bool dfs(vector<int> &nums, vector<bool> &visited, int k, int target, int diff, int idx) {
        if (diff == 0) {
            if (k == 1) {
                return true;
            }
            else {
                return dfs(nums, visited, k - 1, target, target, 0);
            }
        }
        bool flag = false;
        for(int i = idx; i < nums.size(); i ++) {
            if(!visited[i] && nums[i] <= diff) {
                visited[i] = true;
                flag = flag || dfs(nums, visited, k, target, diff - nums[i], i + 1);
                visited[i] = false;
            }
        }
        return flag;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        int n = nums.size();
        vector<bool> visited(n);
        return dfs(nums, visited, k, target, target, 0);
    }
};
