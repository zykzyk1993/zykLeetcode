class Solution {
public:
    vector<string> ans;
    int minDeleteNum=0;
    void dfs(string remainS, int pos, int alreadyDeleteNum, int balance){
        if(alreadyDeleteNum>minDeleteNum)return;
        if(remainS.length()==pos){
            if(balance==0){
                minDeleteNum=alreadyDeleteNum;
                ans.push_back(remainS);
            }
            return;
        }
        if(remainS[pos]==')'){
            if(balance>0)
                dfs(remainS,pos+1,alreadyDeleteNum,balance-1);
            if(pos==0||remainS[pos-1]!=')'){
                remainS.erase(pos,1);
                dfs(remainS,pos,alreadyDeleteNum+1,balance);
            }
        }
        else if(remainS[pos]=='('){
            dfs(remainS,pos+1,alreadyDeleteNum,balance+1);
            if(pos==0||remainS[pos-1]!='('){
                remainS.erase(pos,1);
                dfs(remainS,pos,alreadyDeleteNum+1,balance);
            }
        }
        else
            dfs(remainS,pos+1,alreadyDeleteNum,balance);
    }
  
    vector<string> removeInvalidParentheses(string s) {
        minDeleteNum=s.length();
        dfs(s,0,0,0);
        return ans;
    }
};
