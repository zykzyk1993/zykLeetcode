/*
 * 39. 组合总和
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合
 * 难度：中等
 * 分类：dfs 剪枝
 * 算法：传统dfs 剪枝 回溯
 */
class Solution {
public:
    void dfs(vector<int> &candidates, vector<int> curSet, int target, int index, vector<vector<int>> &res){
        if(target==0){
            res.push_back(curSet);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            //剪枝
            if(candidates[i]>target)break;
            curSet.push_back(candidates[i]);
            dfs(candidates,curSet,target-candidates[i],i,res);
            curSet.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> empty;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,empty,target,0,res);
        return res;
    }
};
