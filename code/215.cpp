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
