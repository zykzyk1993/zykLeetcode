/*
 * 85. 最大矩形
 * 求二进制矩阵中能存在的最大矩形
 * 难度：困难
 * 分类：单调栈
 * 算法：将每一层叠加其以上层的1,然后逐层调用柱状图最大矩形算法
 */
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0)return 0;
        int m=matrix.size(),n=matrix[0].size(),maxArea=0;
        vector<int> heights(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                heights[j]=matrix[i][j]=='1'?heights[j]+1:0;
            }
            maxArea=max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
};
