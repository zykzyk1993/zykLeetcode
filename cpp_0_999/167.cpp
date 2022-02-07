/*
 * 167. 两数之和 II - 输入有序数组
 * 题意：在有序数组中找出和为target的两个数
 * 难度：简单
 * 分类：双指针
 * 算法：左右两个指针根据情况移动
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //vector<int> res;
        int i = 0, j = numbers.size() - 1;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                return {i+1, j+1};
            }
            if(numbers[i]+numbers[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {i+1, j+1};
    }
};
