 /*
 * 198. 打家劫舍
 * 相邻房屋不能一起抢劫，求最大收益
 * 难度：简单
 * 分类：dp
 * 算法：记录抢劫当前房屋和不抢劫的值即可，根据条件更新
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int dpRob=nums[0],dpNotRob=0;
        for(int i=1;i<nums.size();i++){
            int tempRob=dpNotRob+nums[i];
            int tempNotRob=max(dpRob,dpNotRob);
            dpRob=tempRob;
            dpNotRob=tempNotRob;
        }
        return max(dpRob,dpNotRob);
    }
};
