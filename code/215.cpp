/*
 * 215. 数组中的第K个最大元素
 * 在未排序的数组中找到第 k 个最大的元素
 * 难度：中等
 * 分类：数组 快排
 * 算法：使用快排的partition，并采用左右指针的简洁写法
 */
class Solution {
public:
    int partition(vector<int> &nums, int start, int end){
        int pivot=nums[start],i=start, j=end;
        while(i<j){
            while(i<j&&nums[j]>=pivot)j--;
            if(i<j)nums[i]=nums[j];
            while(i<j&&nums[i]<=pivot)i++;
            if(i<j)nums[j]=nums[i];
        }
        nums[i]=pivot;
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1,n=nums.size();
        while(true){
            int pos = partition(nums,l,r);
            if(pos==n-k)return nums[pos];
            if(pos<n-k)l=pos+1;
            else r=pos-1;
        }
    }
};
