/*
 * 301. 删除无效的括号
 * 题意：用最少的操作删除多余的括号，返回所有方案
 * 难度：困难
 * 分类：dfs
 * 算法：先算出需要移除的括号数量
 * 然后dfs，并采用剪枝
 * 首先不删除，其次对于左括号右括号则尝试删除
 * 若和前一个字符相同，则不删除否则重复
 * 对于删除完成的，还需要判断合法性
 */
class Solution {
public:
    vector<string> res;
    void dfs(string s, int start, int remove_left, int remove_right){
        if(remove_left == 0 && remove_right == 0){
            if(isValid(s))
                res.push_back(s);
            return;
        }
        if(remove_left + remove_right > s.size() - start){
            return;
        }
        dfs(s, start+1, remove_left, remove_right);
        if(start > 0 && s[start] == s[start-1]){
            return;
        }
        if(s[start] == '(' && remove_left > 0){
            dfs(s.substr(0, start)+s.substr(start+1), start, remove_left - 1, remove_right);
        }
        if(s[start] == ')' && remove_right > 0){
            dfs(s.substr(0, start)+s.substr(start+1), start, remove_left, remove_right - 1);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int cnt = 0, remove_left = 0, remove_right = 0;
        for(int i = 0; i < s.size(); i ++){
            char c = s[i];
            if(c == ')'){
                cnt++;
                remove_right = max(cnt, remove_right);
            }else if(c == '('){
                cnt--;
            }
        }
        remove_left = max(-cnt, remove_left);
        cnt = 0;
        for(int i = s.size() - 1; i >= 0; i --){
            char c = s[i];
            if(c == '('){
                cnt++;
                remove_left = max(cnt, remove_left);
            }else if(c == ')'){
                cnt--;
            }
        }
        remove_right = max(-cnt, remove_right);
        dfs(s, 0, remove_left, remove_right);
        return res;
    }
    bool isValid(const string &s){
        int cnt = 0;
        for(auto &c:s){
            if(c == '('){
                cnt++;
            }else if(c == ')'){
                if(cnt > 0){
                    cnt--;
                }else{
                    return false;
                }
            }
        }
        return cnt == 0;
    }
};

class Solution {
public:
    vector<string> ans;
    int minDeleteNum=0;
    void dfs(string remainS, int pos, int alreadyDeleteNum, int balance){
        //注意dfs的时候优先走不删除的路径，并且及时剪枝，这样保证结果正确并提升效率
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
