/*
 * 238. 除自身以外数组的乘积
 * 等于 nums 中除 nums[i] 之外其余各元素的乘积，不使用除法
 * 难度：中等
 * 分类：数组
 * 算法：计算前缀后缀乘积
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,1);
        for(int i=1;i<n;i++){
            output[i]=output[i-1]*nums[i-1];
        }
        int product=1;
        for(int i=n-1;i>0;i--){
            product*=nums[i];
            output[i-1]*=product;
        }
        return output;
    }
};
