/*
 * 151. 翻转字符串里的单词
 * 题意：将每个单词作为单位翻转字符串，然后去除前后空格
 * 难度：中等
 * 分类：模拟
 * 算法：翻转每个单词，最后翻转整个字符串，注意最后一步要去除前面的空格
 */
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int left = 0;
        string temp;
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == ' ') {
                if(temp.size() > 0) {
                    reverse(temp.begin(), temp.end());
                    res += temp + " ";
                }
                temp = "";
            }
            else {
                temp += s[i];
            }
        }
        if(temp.size() > 0) {
            reverse(temp.begin(), temp.end());
            res += temp;
        }
        reverse(res.begin(), res.end());
        if (res[0] == ' ') return res.substr(1);
        return res;
    }
};
