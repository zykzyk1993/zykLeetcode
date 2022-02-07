 /*
 * 22. 括号生成
 * 题意：给定括号对数n, 生成所有可能的并且有效的括号组合
 * 难度：中等
 * 分类：DFS
 * 算法：深搜加剪枝，可以记录balance或者记录left，right数量。进一步还可以采用记忆化搜索，某些子树结构是相同的
 */
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
