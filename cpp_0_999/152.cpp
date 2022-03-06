 /*
 * 152. 乘积最大子数组
 * 题意：查找数组中乘积最大的连续子数组
 * 难度：中等
 * 分类：数组
 * 算法：只需要注意同时保存最大值和最小值的情况，然后遇到负数交换最大值和最小值
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,curMax=1,curMin=1;
        for(auto num:nums){
            if(num<0){
                swap(curMax,curMin);
            }
            curMax=max(curMax*num,num);
            curMin=min(curMin*num,num);
            ans=max(ans,curMax);
        }
        return ans;
    }
};
