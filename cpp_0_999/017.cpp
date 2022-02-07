 /*
 * 17. 电话号码的字母组合
 * 题意：手机键盘字母输入
 * 难度：中等
 * 分类：dfs
 * 算法：标准dfs，注意回溯，全局变量
 */
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
