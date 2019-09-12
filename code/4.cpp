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
