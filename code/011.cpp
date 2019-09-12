//双指针法
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
