/*
 * 134. 加油站
 * 题意：给定每次加油及损耗，判断可以从哪个加油站开始循环，无法完成返回-1
 * 难度：中等
 * 分类：贪心
 * 算法：先计算总和，判断能否完成循环，然后找到当前油箱最低状态，后一个加油站即为答案
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int cost_sum = accumulate(cost.begin(), cost.end(), 0);
        if(cost_sum > gas_sum){
            return -1;
        }
        int remain = 0, res = 0;
        for(int i=0;i<n;i++){
            remain += gas[i]-cost[i];
            if(remain<0){
                res = (i+1)%n;
                remain = 0;
            }
        }
        return res;
    }
};
