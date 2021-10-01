/*
 * 633. 平方数之和
 * 题意：判断给定数字是否是两数平方和
 * 难度：中等
 * 分类：双指针
 * 算法：从0到sqrt(c)双指针遍历
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0, j=(int)(sqrt(c));
        while(i<=j){
            int diff = c - i*i - j*j;
            if(diff == 0){
                return true;
            }
            if(diff > 0){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};
