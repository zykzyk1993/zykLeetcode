/*
 * 367. 有效的完全平方数
 * 题意：判断是否为完全平方数
 * 难度：简单
 * 分类：二分
 * 算法：二分求平方根
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        long long low = 0, high = num - 1, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(mid * mid == num) {
                return true;
            }
            else if(mid * mid < num) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return false;   
    }
};
