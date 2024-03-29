/*
 * 84. 柱状图中的最大矩形
 * 求柱状数组中能存在的最大矩形
 * 难度：困难
 * 分类：单调栈
 * 算法：维护单调递增栈，每次需要出栈的时候(考虑栈顶柱子，当前柱子和第二栈顶柱子即为左右边界)，此时计算矩形面积
 */
//单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        //为了方便
        heights.push_back(-1);
        int maxArea=0,n=heights.size();
        for(int i=0;i<n;i++){
            while(!s.empty()&&heights[s.top()]>heights[i]){
                int h=heights[s.top()];
                s.pop();
                int left=s.empty()?0:s.top()+1;
                maxArea=max(maxArea,(i-left)*h);
            }
            s.push(i);
        }
        return maxArea;
    }
};

//双单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0)return 0;
        int ans=0;
        stack<int> left,right;
        vector<int> leftVol(heights.size(),0),rightVol(heights.size(),0);
        for(int i=0;i<heights.size();i++){
            int leftBound=-1;
            while(!left.empty()&&heights[left.top()]>=heights[i])left.pop();
            if(!left.empty())leftBound=left.top();
            leftVol[i]=heights[i]*(i-leftBound-1);
            left.push(i);
        }
        for(int i=heights.size()-1;i>=0;i--){
            int rightBound=heights.size();
            while(!right.empty()&&heights[right.top()]>=heights[i])right.pop();
            if(!right.empty())rightBound=right.top();
            rightVol[i]=heights[i]*(rightBound-i-1);
            right.push(i);
        }
        for(int i=0;i<heights.size();i++)
            ans=max(ans,leftVol[i]+rightVol[i]+heights[i]);
        return ans;
    }
};
