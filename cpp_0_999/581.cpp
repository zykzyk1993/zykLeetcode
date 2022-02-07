/*
 * 581. 最短无序连续子数组
 * 找到最短的连续子数组，把它变成升序则整个数组变升序
 * 难度：简单
 * 分类：数组
 * 算法：排序后比对
 *      或者一遍遍历，找到左边和右边第一个逆序的位置，然后遍历判断它们的真实位置，速度更快且不需要额外空间
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums);
        sort(nums.begin(),nums.end());
        int n = nums.size(),i=0,j=n-1;
        while(i<=j&&temp[i]==nums[i])i++;
        while(i<=j&&temp[j]==nums[j])j--;
        return j-i+1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(),left=-1,right=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                left=i;
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                right=i;
                break;
            }
        }
        if(left==right)return 0;
        int minVal=INT_MAX,maxVal=INT_MIN;
        for(int i=left;i<=right;i++){
            minVal=min(minVal,nums[i]);
            maxVal=max(maxVal,nums[i]);
        }
        int i=left-1,j=right+1;
        while(i>=0&&nums[i]>minVal)i--; //必须比这个最小值小 其前面的才能保证都小
        while(j<n&&nums[j]<maxVal)j++; //必须比这个最大值大 其后面的才能保证都大
        return j-i-1;
    }
};

//2021
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minn = nums[n-1], maxn = nums[0], begin = 0, end = -1;
        for(int i = 0; i < n; i ++){
            if(nums[i] < maxn){
                end = i;
            }else{
                maxn = nums[i];
            }

            if(nums[n-1-i] > minn){
                begin = n-1-i;
            }else{
                minn = nums[n-1-i];
            }
        }
        return end-begin+1;
    }
};
