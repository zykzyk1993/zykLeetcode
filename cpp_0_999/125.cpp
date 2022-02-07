/*
 * 125. 验证回文串
 * 题意：验证回文串，忽略空格和其他字符，忽略大小写
 * 难度：简单
 * 分类：字符串
 * 算法：双指针模拟
 */
class Solution {
public:
    bool valid(char c) {
        if (c <= '9' && c >= '0') {
            return true;
        }
        if (c <= 'z' && c >= 'a') {
            return true;
        }
        if (c <= 'Z' && c >= 'A') {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size();
        while(i < j) {
            while(i < j && !valid(s[i])) {
                i ++;
            }
            while(i < j && !valid(s[j])) {
                j --;
            }
            if(i < j) {
                if (s[i] <= 'z' && s[i] >= 'a') {
                    s[i] = (char)(s[i] -'a' + 'A');
                }
                if (s[j] <= 'z' && s[j] >= 'a') {
                    s[j] = (char)(s[j] -'a' + 'A');
                }
                if (s[i] != s[j]) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};
