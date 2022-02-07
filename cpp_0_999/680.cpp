/*
 * 680. 验证回文字符串 Ⅱ
 * 题意：最多删除一个字符是否能变成回文串
 * 难度：简单
 * 分类：字符串 模拟
 * 算法：遍历模拟，注意有两种情况，删除左字符或右字符，可以采用遍历两次或者递归
 */
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        bool deleted = false, valid=true;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
                continue;
            }
            if(deleted){
                valid=false;
                break;
            }
            
            if(!deleted && s[l]==s[r-1]){
                r--;
                deleted=true;
            }
            else{
                valid=false;
                break;
            }
        }
        if(valid)
            return true;
        l = 0, r = s.size()-1;
        deleted = false, valid=true;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
                continue;
            }
            if(!deleted && s[l+1]==s[r]){
                l++;
                deleted=true;
            }
            else{
                valid=false;
                break;
            }
        }
        return valid;
    }
};
