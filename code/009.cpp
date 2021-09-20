/*
 * 9. 回文数
 * 题意：返回数组中和为给定数的下标
 * 难度：简单
 * 分类：字符串
 * 算法：模拟 注意溢出
 */
class Solution {
public:
    int reverse(int x) {
        int ans=0,maxAns=INT_MAX/10;
        while(x){
            if(ans>maxAns)return 0;
            int digit=x%10;
            ans=ans*10+digit;
            x=x/10;
        }
        return ans;
    }
    bool isPalindrome(int x) {
        if(x<0)return false;
        return x==reverse(x);
    }
};
