/*
 * 4. 寻找两个有序数组的中位数
 * 题意：两个有序数组，找出中位数，要求复杂度O(logN)
 * 难度：困难
 * 分类：数组，二分，分治
 * 算法：转化为查找第K大的数，取两个数组的min(k/2,len)作比较，从而每次缩小问题规模为k/2，注意边界和下标
 */
class Solution {
public:
    int findKthNumber(vector<int>& nums1,vector<int>& nums2, int start1, int end1, int start2, int end2, int k){
        int s1=end1-start1+1,s2=end2-start2+1;
        if(s1<s2){
            return findKthNumber(nums2,nums1,start2,end2,start1,end1,k);
        }
        if(s2<=0){
            return nums1[start1+k-1];
        }
        if(k==1){
            return min(nums1[start1],nums2[start2]);
        }
        if(s2>=k/2){
            int temp1=nums1[start1+k/2-1],temp2=nums2[start2+k/2-1];
            if(temp1>=temp2){
                return findKthNumber(nums1,nums2,start1,end1,start2+k/2,end2,k-k/2);
            }else{
                return findKthNumber(nums1,nums2,start1+k/2,end1,start2,end2,k-k/2);
            }
        }else{
            int temp1=nums1[start1+k/2-1],temp2=nums2[end2];
            if(temp1>=temp2){
                return nums1[start1+k-1-s2];
            }else{
                return findKthNumber(nums1,nums2,start1+k/2,end1,start2,end2,k-k/2);
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size(),s2=nums2.size();
        findKthNumber(nums1,nums2,0,s1-1,0,s2-1,(s1+s2)/2+1);
        if((s1+s2)%2==0){
            return (findKthNumber(nums1,nums2,0,s1-1,0,s2-1, (s1+s2)/2) + findKthNumber(nums1,nums2,0,s1-1,0,s2-1,(s1+s2)/2+1))/2.0;
        }else{
            return findKthNumber(nums1,nums2,0,s1-1,0,s2-1, (s1+s2)/2+1)*1.0;
        }
    }
};

//2021
class Solution {
public:
    int findKthNum(vector<int> &nums1, vector<int> &nums2, int start1, int start2, int k){
        if (nums1.size() - start1 < nums2.size() - start2) {
            return findKthNum(nums2, nums1, start2, start1, k);
        }
        if (start2 >= nums2.size()) {
            return nums1[start1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        int s2 = nums2.size() - start2;
        int l2 = min(k/2, s2);
        int l1 = k - l2;
        int pos1 = start1 + l1 - 1;
        int pos2 = start2 + l2 - 1;
        if(nums1[pos1] == nums2[pos2]){
            return nums1[pos1];
        }
        else if(nums1[pos1] < nums2[pos2]) {
            return findKthNum(nums1, nums2, pos1 + 1, start2, l2);
        }
        else {
            return findKthNum(nums1, nums2, start1, pos2 + 1, l1);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum % 2 == 1){
            return findKthNum(nums1, nums2, 0, 0, sum / 2 + 1);
        }
        else {
            return (findKthNum(nums1, nums2, 0, 0, sum / 2) + findKthNum(nums1, nums2, 0, 0, sum / 2 + 1)) * 0.5;
        }
    }
};
