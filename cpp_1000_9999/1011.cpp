/*
 * 1011. 在 D 天内送达包裹的能力
 * 题意：必须按照顺序连续装货物，在D天内运完，求最小的载重
 * 难度：中等
 * 分类：二分
 * 算法：二分答案，判断给定天数是否能运送完成，注意low为最大货物数量(n天)，high为所有货物总和(1天内)
 */

class Solution {
public:
    bool C(vector<int>& weights, int days, int total){
        int day = 1, sum = 0;
        for(auto &weight:weights){
            if(sum + weight > total){
                sum = 0;
                day++;
            }
            sum += weight;
        }
        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0, mid;
        for(auto &weight:weights){
            low = max(low, weight);
            high += weight;
        }
        while(low <= high){
            mid = low + (high - low) / 2;
            if(C(weights, days, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
