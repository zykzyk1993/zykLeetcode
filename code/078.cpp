/*
 * 78. 子集
 * 给定不重复元素，返回子集(幂集)
 * 难度：中等
 * 分类：位运算 dfs
 * 算法：相当于使用每一位来决定是否选该数字，或使用dfs
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if((i>>j)&1)temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
