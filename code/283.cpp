class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zeroCnt++;
            else nums[i-zeroCnt]=nums[i];
        }
        for(int i=nums.size()-zeroCnt;i<nums.size();i++){
            nums[i]=0;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};
