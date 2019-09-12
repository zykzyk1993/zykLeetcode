class Solution {
public:
    void dfs(int n, int balance, string curString,vector<string> &ans){
        if(curString.size()==2*n){
            if(balance==0){
                ans.push_back(curString);
            }
            return;
        }
        if(balance>0){
            dfs(n,balance-1,curString+')',ans);
        }
        if(2*n-curString.size()>balance){
            dfs(n,balance+1,curString+'(',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0)return ans;
        dfs(n,0,"",ans);
        return ans;
    }
};
