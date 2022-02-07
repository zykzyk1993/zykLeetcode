/*
 * 678. 有效的括号字符串
 * 题意：判断是否是有效的括号字符串，其中*可以任意代替一个括号字符或者当作空字符
 * 难度：中等
 * 分类：字符串 贪心
 * 算法：在原先括号计算balance基础上，增加记录star_num。注意需要正向做一遍以及反向做一遍
 */
class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0, star_num = 0;
        for(auto &c:s) {
            if (c == '(') {
                balance ++;
            }
            else if (c == ')') {
                if (balance > 0) {
                    balance --;
                }
                else if (star_num > 0) {
                    star_num --;
                }
                else {
                    return false;
                }
            }
            else {
                star_num ++;
            }
        }
        if (balance > star_num) {
            return false;
        }
        reverse(s.begin(), s.end());
        balance = 0, star_num = 0;
        for(auto &c:s) {
            if (c == ')') {
                balance ++;
            }
            else if (c == '(') {
                if (balance > 0) {
                    balance --;
                }
                else if (star_num > 0) {
                    star_num --;
                }
                else {
                    return false;
                }
            }
            else {
                star_num ++;
            }
        }
        if (balance > star_num) {
            return false;
        }
        return true;
    }
};
