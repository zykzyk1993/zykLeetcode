/*
 * 40. 组合总和 II
 * 题意：返回和为target的组合总数，不能重复
 * 难度：中等
 * 分类：dfs
 * 算法：同39题dfs,注意如果两个数字相同，后面那个数字必须在前一个数字被选的情况下才可以被选择
 */
class Solution {
public:
    void dfs(vector<int> &candidates, vector<int> &cur, int remain, int pos, bool push_last, vector<vector<int>> &ans){
        if(remain == 0){
            ans.push_back(cur);
            return;
        }
        if(pos==candidates.size()){
            return;
        }
        dfs(candidates, cur, remain, pos+1, false, ans);
        if(remain>=candidates[pos]){
            if(pos>0 && candidates[pos]==candidates[pos-1] && push_last==false){
                return;
            }
            cur.emplace_back(candidates[pos]);
            dfs(candidates, cur, remain-candidates[pos], pos+1, true, ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size()==0)
            return ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        reverse(candidates.begin(), candidates.end());
        dfs(candidates, cur, target, 0, false, ans);
        return ans;
    }
};
