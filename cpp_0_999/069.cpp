/*
 * 69. Sqrt(x)
 * 题意：求算术平方根
 * 难度：简单
 * 分类：二分
 * 算法：经典数学二分
 */
class Solution {
public:
    int mySqrt(int x) {
        long long l=1;
        long long r=(long long)x+1;
        long long m;
        while(l<r){
            m=(l+r)/2;
            if(m*m<=x)l=m+1;
            else r=m;
        }
        return l-1;
    }
};
