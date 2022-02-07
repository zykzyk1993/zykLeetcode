/*
 * 442. 数组中重复的数据
 * 题意：数组中所有元素不是出现一次就是两次，求所有两次的元素，元素范围在1～n
 * 难度：中等
 * 分类：数组
 * 算法：原地哈希，将出现过的数组元素对应idx位置置为负
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++) {
            int idx = nums[i] >= 0 ? nums[i] : -nums[i];
            if (nums[idx - 1] < 0) {
                res.push_back(idx);
            }
            else {
                nums[idx - 1] = -nums[idx - 1];
            }
        }
        return res;
    }
};
