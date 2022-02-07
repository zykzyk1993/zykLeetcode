/*
 * 263. 丑数
 * 题意：判断一个数因子是否只有2 3 5
 * 难度：简单
 * 分类：数学
 * 算法：while循环
 */
class Solution {
public:
    bool isUgly(int n) {
        if(n == 0)return false;
        while(n%2==0){
            n/=2;
        }
        while(n%3==0){
            n/=3;
        }
        while(n%5==0){
            n/=5;
        }
        return n==1;
    }
};
