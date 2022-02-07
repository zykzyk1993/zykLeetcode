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

class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
