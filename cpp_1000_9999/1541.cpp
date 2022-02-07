/*
 * 1541. 平衡括号字符串的最少插入次数
 * 题意：一个左括号需要两个连续的右括号平衡，求平衡括号字符串的最少插入次数
 * 难度：中等
 * 分类：贪心
 * 算法：用left保存当前多余左括号，遇到右括号，如果只有一个先补上，然后判断和左括号的平衡。详细见注释
 */
class Solution {
public:
    int minInsertions(string s) {
        int res = 0, left = 0;
        for(int i = 0; i < s.size(); i ++) {
            if (s[i] == '(') {
                left ++; // 遇到左括号，增加left
            }
            else {
                if (i < s.size() - 1 && s[i+1] == ')') {
                    i ++; // 如果下一个为右括号跳到下一个
                }
                else {
                    res ++; // 否则需要补充一个右括号
                } // 完成补充后
                if (left > 0) { // 如果有多余左括号则平衡一次
                    left --;
                }
                else {
                    res ++; // 否则补充左括号
                }
            }
        }
        return res + 2 * left; // 返回补充次数和剩余左括号2倍之和
    }
};
