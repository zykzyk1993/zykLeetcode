/*
 * 283. 移动零
 * 编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序，操作尽量少
 * 难度：简单
 * 分类：数组
 * 算法：交换或者计数然后替换
 */
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
