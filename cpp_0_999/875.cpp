/*
 * 875. 爱吃香蕉的珂珂
 * 题意：好几堆香蕉，最低在多少的速度下，能在指定时间内吃完
 * 难度：中等
 * 分类：二分答案
 * 算法：二分答案，判定sum((p-1)/k+1)<=h
 */
class Solution {
public:
    bool C(vector<int>& piles, int h, int k){
        int sum = 0;
        for(auto &pile:piles){
            sum += (pile - 1)/k + 1;
        }
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = pow(10, 9), mid;
        while(low <= high){
            mid = low + (high - low)/ 2;
            if(C(piles, h, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
