/*
 * 557. 反转字符串中的单词 III
 * 题意：反转字符串当中的所有单词的顺序
 * 难度：简单
 * 分类：字符串
 * 算法：逐个翻转每个单词，然后翻转整个字符串
 */
class Solution {
public:
    string reverseWords(string s) {
        string temp, res;
        for(auto &c:s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    reverse(temp.begin(), temp.end());
                    res += temp + " ";
                    temp = "";
                }
            }
            else {
                temp += c;
            }
        }
        reverse(temp.begin(), temp.end());
        res += temp;
        if (res.back() == ' ') res.pop_back();
        return res;
    }
};
