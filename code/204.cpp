/*
 * 204. 计数质数
 * 题意：计算小于n的质数个数
 * 难度：中等
 * 分类：数学
 * 算法：埃氏筛查法
 */
//标准埃氏筛
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n, false);
        for(int i = 2; i < n; i++){
            if(prime[i]) continue;
            res ++;
            int j = 2 * i;
            while(j < n){
                prime[j] = true;
                j += i;
            }
        }
        return res;
    }
};

//去除偶数 加速
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        int res = 1;
        vector<bool> prime(n, false);
        for(int i = 3; i < n; i+=2){
            if(prime[i]) continue;
            res ++;
            int j = 3 * i;
            while(j < n){
                prime[j] = true;
                j += 2 * i;
            }
        }
        return res;
    }
};
