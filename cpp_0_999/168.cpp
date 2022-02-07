/*
 * 168. Excel表列名称
 * 题意：给定整数，返回excel表中对应的列名称
 * 难度：简单
 * 分类：数学，模拟
 * 算法：10进制转26进制，注意是从1开始计算，所以每次都得先将数字减1
 */
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber){
            columnNumber --;
            res += ('A' + columnNumber % 26);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
