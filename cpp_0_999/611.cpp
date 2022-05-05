/*
 * 611. 有效三角形的个数
 * 题意：返回数组中任选三个数能够组成三角形的组数
 * 难度：中等
 * 分类：双指针
 * 算法：排序以后双指针，注意优化，固定i和j后，k是从左往右递增的
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i ++) {
            if (nums[i] <= 0) continue;
            int k = i + 2;
            for(int j = i + 1; j < n - 1; j ++) {
                while(k < n && nums[i] + nums[j] > nums[k]) {
                    k ++;
                }
                k --;
                res += k - j;
            }
        }
        return res;
    }
};
