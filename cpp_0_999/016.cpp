 /*
 * 16. 最接近的三数之和
 * 题意：找出数组中和最接近target的和
 * 难度：中等
 * 分类：数组，双指针
 * 算法：双指针，注意记录diff和ans
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int diff = ans - target;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum = nums[i]+ nums[l] + nums[r];
                int cur_diff = sum - target;
                if(abs(diff) > abs(cur_diff)) {
                    ans = target+cur_diff;
                    diff = cur_diff;
                }
                if(cur_diff==0){
                    return target;
                }else if(cur_diff<0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};
