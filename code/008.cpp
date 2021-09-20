/*
 * 8. 字符串转换整数 (atoi)
 * 题意：给定一定规则，实现atoi
 * 难度：中等
 * 分类：字符串 模拟
 * 算法：注意判断非字符，符号，溢出，获取每一个digit
 */
class Solution {
public:
    int convertToInt(string s, int sign){
        if(s.size()==0){
            return 0;
        }
        int i = 0;
        while(i < s.size() && s[i] == '0'){
            i++;
        }
        if(i==s.size())
            return 0;
        int res = 0;
        for(int idx=i;idx<s.size();idx++){
            int digit = s[idx] - '0';
            if(res > INT_MAX / 10){
                return INT_MAX;
            }else if(res < INT_MIN / 10) {
                return INT_MIN;
            }else if(res == INT_MAX/10 && digit > INT_MAX - res * 10){
                return INT_MAX;
            }else if(res == INT_MIN/10 && digit > res * 10 - INT_MIN){
                return INT_MIN;
            }
            res = res * 10 + digit * sign;
        }
        return res;
    }
    int myAtoi(string s) {
        int i = 0;
        string valid_str = "";
        while(s[i] == ' ' && i < s.size()){
            i++;
        }
        int sign=1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            sign=1;
            i++;
        }
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            valid_str += s[i];
            i++;
        }
        return convertToInt(valid_str, sign);
    }
};
