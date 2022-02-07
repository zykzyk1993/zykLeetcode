 /*
 * 11. 盛最多水的容器
 * 题意：数组下标代表横坐标，数组中的值代表纵坐标，求最大面积
 * 难度：中等
 * 分类：数组，双指针
 * 算法：从两边向中间遍历，复杂度为O(N)，优先选择小的一边往里遍历
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int vol=min(height[i],height[j])*(j-i);
            res=max(res,vol);
            if(height[i]<=height[j])i++;
            else j--;
        }
        return res;
    }
};
