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
