/*
* 31. 下一个排列
* 题意：找到下一个排列组合，即下一个大整数
* 难度：中等
* 分类：数组
* 算法：找到要交换的两个数，左侧较小数尽量靠右，右侧较大数尽量小，交换后，较大数后面的需要重新升序排列
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return;
        }
        //找到较小数candidate和较大数swap_idx
        int max_idx=n-1, candidate=-1;
        for(int i=n-2;i>=0;i--){
            //找到升序的点
            if(nums[i]<nums[max_idx]){
                candidate=i;
                break;
            //否则更新最大idx
            }else if(nums[i]>nums[max_idx]){
                max_idx=i;
            }
        }
        if(candidate>=0){
            int swap_idx=max_idx;
            for(int i=n-1;i>candidate;i--){
                if(nums[i]<=nums[candidate])
                    continue;
                else if(nums[i]<nums[swap_idx]){
                    swap_idx=i;
                }
            }
            swap(nums[candidate],nums[swap_idx]);
        }
        int i=candidate+1,j=n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};
