 /*
 * 18. 四数之和
 * 题意：四数之和为target
 * 难度：中等
 * 分类：双指针
 * 算法：双循环+双指针 注意判断重复数字且时刻注意边界，还可以加入剪枝
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans; 
        if(nums.size()<4)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int l=j+1,r=nums.size()-1;
                while(l<r){
                    long long sum = (long long)nums[l]+(long long)nums[r]+(long long)nums[i]+(long long)nums[j];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l<r&&nums[l]==nums[l-1])l++;
                        while(l<r&&nums[r]==nums[r+1])r--;
                    }else if(sum<target){
                        l++;
                        while(l<r&&nums[l]==nums[l-1])l++;
                    }else{
                        r--;
                        while(l<r&&nums[r]==nums[r+1])r--;
                    }
                }
            }
        }
        return ans;
    }
};
