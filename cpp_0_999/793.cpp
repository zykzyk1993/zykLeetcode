/*
 * 793. 阶乘函数后 K 个零
 * 题意：求阶乘函数后为K个零的数有多少个
 * 难度：困难
 * 分类：数学 二分
 * 算法：采用求阶乘后0的个数作为辅助函数，采用二分查找，找到了返回5，找不到返回0
 */
class Solution {
public:
    long long cntZeros(long long k){
        long long res = 0;
        while(k){
            k = k / 5;
            res += k;
        }
        return res;
    }
    int preimageSizeFZF(int k) {
        long long low = 0, high = __LONG_LONG_MAX__, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(cntZeros(mid) == k){
                return 5;
            }
            else if(cntZeros(mid) < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return 0;
    }
};
