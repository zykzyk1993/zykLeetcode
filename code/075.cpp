//经典荷兰国旗问题
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int p=0;
        while(p<=right){
            if(nums[p]==0){
                swap(nums[p],nums[left]);
                left++;
                p++;
            }else if(nums[p]==1){
                p++;
            }else{
                swap(nums[p],nums[right]);
                right--;
            }
        }
    }
};
//对于K种颜色的推广，先排好颜色0和颜色k-1到数组的两端，再继续调用
