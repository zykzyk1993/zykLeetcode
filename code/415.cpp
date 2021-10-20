/*
 * 415. 字符串相加
 * 题意：将两个字符串代表的数字相加返回字符串
 * 难度：中等
 * 分类：数学，模拟
 * 算法：反转，按照进位相加，反转
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = max(num1.size(), num2.size());
        string res = "";
        int carry = 0;
        for(int i = 0; i < n; i++){
            int n1 = i>=num1.size()?0:(num1[i]-'0');
            int n2 = i>=num2.size()?0:(num2[i]-'0');
            int sum = n1 + n2 + carry;
            res += '0' + sum%10;
            carry = sum/10;
        }
        if(carry > 0){
            res+='1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
