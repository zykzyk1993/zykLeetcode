/*
 * 88. 合并两个有序数组
 * 题意：合并两个有序数组到数组1当中
 * 难度：简单
 * 分类：双指针
 * 算法：双指针记录更新，从后往前遍历
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        m--;
        n--;
        while(m>=0 && n>=0){
            if(nums1[m]>nums2[n]){
                nums1[pos]=nums1[m];
                m--;
            }else{
                nums1[pos]=nums2[n];
                n--;
            }
            pos--;
        }
        while(n>=0){
            nums1[pos]=nums2[n];
            n--;
            pos--;
        }
    }
};
