class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
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
        while(!s.empty()){
            int h=heights[s.top()];
            s.pop();
            int left=s.empty()?0:s.top()+1;
            maxArea=max(maxArea,(n-left)*h);
        }
        return maxArea;
    }
};
