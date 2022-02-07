/*
 * 172. 阶乘后的零
 * 题意：计算n的阶乘结果末尾0的个数
 * 难度：中等
 * 分类：数学
 * 算法：其实就是计算包含多少个5的因子，注意可以通过第二种方法快速计算
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i=5;i<=n;i++){
            int j = i;
            while(j%5==0){
                res ++;
                j/=5;
            }
        }
        return res;
    }
};

//第一次加上的为包含1个5因子的个数，以此类推
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n){
            n/=5;
            res+=n;
        }
        return res;
    }
};
