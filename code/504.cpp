/*
 * 504. 七进制数
 * 题意：7进制转10进制字符串
 * 难度：简单
 * 分类：数学
 * 算法：进制转换，注意负数和溢出
 */
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)return "0";
        long long n = num>0?num:-num;
        stack<int> s;
        while(n){
            s.push(n%7);
            n/=7;
        }
        string res;
        while(!s.empty()){
            res+=('0'+s.top());
            s.pop();
        }
        if(num<0){
            res = "-"+res;
        }
        return res;
    }
};
