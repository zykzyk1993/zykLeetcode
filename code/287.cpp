/*
 * 287. 寻找重复数
 * 题意：长度为n+1的数组，包含1到n的数，求唯一的一个重复数
 * 难度：中等
 * 分类：数组
 * 算法：如果把该数组理解为链表，则可以利用双指针找链表中的环
 * 或通过交换，每次尽可能把1到n归位，总会发生冲突得到答案
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int pre1 = 0;
        int pre2 = slow;
        while(pre1 != pre2){
            pre1 = nums[pre1];
            pre2 = nums[pre2];
        }
        return pre1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            if(nums[i] == i+1){
                continue;
            }
            else if(nums[i] == nums[nums[i] - 1]) {
                return nums[i];
            }else{
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        return 1;
    }
};
