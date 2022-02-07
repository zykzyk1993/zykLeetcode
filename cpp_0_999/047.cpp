/*
 * 47. 全排列 II
 * 题意：同上题，输入中可能有重复元素，返回不重复排列
 * 难度：中等
 * 分类：dfs 回溯
 * 算法：同46题，唯一不同的是避免重复，需要排序，如果有前一个元素、相同且未选取，当前元素也不可以选取，否则重复
 */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, vector<bool> &visited, vector<int> &temp){
        int n = nums.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(i > 0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
                temp.push_back(nums[i]);
                visited[i]=true;
                dfs(nums, visited, temp);
                temp.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n);
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(nums, visited, temp);
        return ans;
    }
};
