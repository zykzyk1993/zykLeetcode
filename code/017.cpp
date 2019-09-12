class Solution {
public:
    vector<string> ans;
    vector<string> num2char={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string &digits, int curIndex, string curString){
        if(curIndex==digits.size()){
            ans.push_back(curString);
            return;
        }
        for(auto c:num2char[digits[curIndex]-'0']){
            dfs(digits,curIndex+1,curString+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return ans;
        dfs(digits,0,"");
        return ans;
    }
};
