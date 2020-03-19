/*
 * 300. 最长上升子序列
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度
 * 难度：中等
 * 分类：dp 二分
 * 算法：传统DP，注意可以使用二分，维持单调序列来进行优化
 */
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
	    vector<int> res;
	    for(int i=0; i<nums.size(); i++) {
	        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
	        if(it==res.end()) res.push_back(nums[i]);
	        else *it = nums[i];
	    }
	    return res.size();
	}
};
