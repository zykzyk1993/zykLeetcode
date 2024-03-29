/*
 * 312. 戳气球
 * 逐个戳破气球序列，没戳破一个气球获得当前气球和相邻气球的奖励，戳破后就不存在
 * 难度：困难
 * 分类：dp 区间dp
 * 算法：使用dp[start][end]来表示，注意递推方式为考虑splitIdx为范围内最后一个被戳破气球来递推
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int l=nums.size();
        if(l==0)return 0;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(l+2,vector<int>(l+2));
        for(int len=1;len<=l;len++){ //sequence length
            for(int start=1;start<=l-len+1;start++){ //start point = i ,end point = i+len-1
                int end=start+len-1;
                for(int split=start;split<=end;split++)
                    //关键要理解split是范围内最后一个被戳破的气球
                    dp[start][end]=max(dp[start][end],dp[start][split-1]+dp[split+1][end]+nums[start-1]*nums[split]*nums[end+1]);
            }
        }
        return dp[1][l];
    }
};
