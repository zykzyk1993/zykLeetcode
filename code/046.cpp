class Solution {
public:
    void dfs(vector<int>& nums, vector<int> &curNums, vector<bool> &visited, vector<vector<int>> &res){
        if(curNums.size()==nums.size()){
            res.push_back(curNums);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                curNums.push_back(nums[i]);
                dfs(nums,curNums,visited,res);
                curNums.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n==0)return res;
        vector<bool> visited(n,false);
        vector<int> empty;
        dfs(nums,empty,visited,res);
        return res;
    }
};
