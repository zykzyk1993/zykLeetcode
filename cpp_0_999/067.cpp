/*
 * 67. 二进制求和
 * 题意：二进制字符串求和
 * 难度：简单
 * 分类：数学，模拟
 * 算法：参考十进制思路
 */
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;
        int carry = 0;
        for(int i = 0; i < max(a.size(), b.size()); i++){
            int n1 = i >= a.size()?0:(a[i] - '0');
            int n2 = i >= b.size()?0:(b[i] - '0');
            int sum = n1+n2+carry;
            res += (sum % 2) + '0';
            carry = sum / 2;
        }
        if(carry){
            res += "1";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
