/*
 * 1047. 删除字符串中的所有相邻重复项
 * 题意：每次可以删除字符串中的相邻的两个重复字符，可以重复在删除后的基础上操作知道无法操作
 * 难度：简单
 * 分类：栈
 * 算法：实际上只需要用栈的思想保存到string中，如果末尾字符和当前字符相同则弹出，否则推入，最终就是结果
 */
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for(auto &c:s) {
            if (!res.empty() && res.back() == c) {
                res.pop_back();
            }
            else {
                res.push_back(c);
            }
        }
        return res;
    }
};
