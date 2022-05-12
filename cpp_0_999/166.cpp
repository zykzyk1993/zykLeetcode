/*
 * 166. 分数到小数
 * 题意：将分数转化为小数，循环部分用括号表示
 * 难度：中等
 * 分类：数学 字符串
 * 算法：注意符号和整型溢出，然后用哈希表保存余数和对应位数，遇到重复的则说明循环
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        bool sign = (numerator < 0) ^ (denominator < 0); 
        long numeratorL = abs(numerator);
        long denominatorL = abs(denominator);
        if (sign && numerator != 0) {
            res += "-";
        }
        long int_part = numeratorL / denominatorL;
        res += to_string(int_part);
        if (numeratorL % denominatorL == 0) {
            return res;
        }
        res += ".";
        long remain = numeratorL % denominatorL;
        unordered_map<int, int> m; // <余数，位数>
        int digit = 0;
        string remain_part;
        while(remain) {
            remain *= 10;
            if (m.count(remain)) {
                remain_part.insert(m[remain], "(");
                remain_part.push_back(')');
                break;
            }
            m[remain] = digit;
            remain_part += to_string(remain / denominatorL);
            remain = remain % denominatorL;
            digit ++;
        }
        res += remain_part;
        return res;
    }
};
