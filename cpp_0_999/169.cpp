 /*
 * 169. 多数元素
 * 查找数组中的多数元素
 * 难度：简单
 * 分类：数组
 * 算法：记录当前数字出现的cnt，若不是则减1，否则加1，清零后取下一个数字，最后会留下多数元素
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,curNum=nums[0];
        for(auto num:nums){
            if(cnt==0){
                curNum=num;
            }
            if(curNum==num)cnt++;
            else cnt--;
        }
        return curNum;
    }
};
