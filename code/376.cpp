/*
 * 376. 摆动序列
 * 题意：最长的一上一下摆动的子序列
 * 难度：中等
 * 分类：dp
 * 算法：双dp数组，注意注释中的转移方程
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        int ans = 1;
        /**
        * dp1代表结尾为上升序列，dp2代表结尾为下降的序列
        * 当前数和前一个数相等，则和前一个值相等
        */
        for(int i = 1; i < n; i++){
            if (nums[i] < nums[i-1]){
                //此时，要么nums[i-1]可以作为dp2[i-1]的结尾元素(或小于dp2[i-1]的结尾)，自然可以转移
                //要么，nums[i-1]大于dp2[i-1]结尾，则nums[i]更大于dp2[i-1]结尾，自然可以转移
                dp1[i] = max(dp1[i], dp2[i-1]+1); 
                //不能转移，效果等同
                dp2[i] = dp2[i-1];
            }else if(nums[i] > nums[i-1]){
                dp2[i] = max(dp2[i], dp1[i-1]+1);
                dp1[i] = dp1[i-1];
            }else{
                dp1[i] = dp1[i-1];
                dp2[i] = dp2[i-1];
            }
            ans = max(ans, max(dp1[i], dp2[i]));
        }
        return ans;
    }
};
