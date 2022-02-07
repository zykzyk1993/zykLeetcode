/*
 * 77. 组合
 * 题意：给定n，k， 返回1到n选择k个的所有组合
 * 难度：中等
 * 分类：dfs 回溯
 * 算法：经典dfs回溯
 */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int &n, int idx, vector<int> &temp, int &k){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i = idx+1; i <= n; i++){
            temp.push_back(i);
            dfs(n, i, temp, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        dfs(n, 0, temp, k);
        return ans;
    }
};
