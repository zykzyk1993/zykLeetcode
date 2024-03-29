 /*
 * 15. 三数之和
 * 题意：找出数组中所有和为0的三元组合
 * 难度：中等
 * 分类：数组，双指针
 * 算法：排序，从前往后，固定第一个元素，后续元素用双指针来做，注意去掉重复元素
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; 
        if(nums.size()<3)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]+nums[i]==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r&&nums[l]==nums[l-1])l++;
                    while(l<r&&nums[r]==nums[r+1])r--;
                }else if(nums[l]+nums[r]+nums[i]<0){
                    l++;
                    while(l<r&&nums[l]==nums[l-1])l++;
                }else{
                    r--;
                    while(l<r&&nums[r]==nums[r+1])r--;
                }
            }
        }
        return ans;
    }
};
