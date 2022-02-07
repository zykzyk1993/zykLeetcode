/*
 * 42. 接雨水
 * 计算柱形图所能装下的雨水数量
 * 难度：困难
 * 分类：数组 栈 双指针
 * 算法：三种方法:1.DP先求出来每个位置的maxleft,maxright，再遍历一遍;2.两个指针，类似lc11题的思路;3.用栈数据结构;
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        if(height.size()<3)return ans;
        //从左往右遍历，记录当前柱子和左侧柱子的差值，直到遇到比当前更高的柱子，更新ans和maxIndex
        int curLeftHeight=height[0],tempVolume=0,maxIndex=0;
        for(int i=1;i<height.size();i++){
            if(height[i]>=curLeftHeight){
                maxIndex=i;
                ans+=tempVolume;
                tempVolume=0;
                curLeftHeight=height[i];
            }else{
                tempVolume+=curLeftHeight-height[i];
            }
        }
        //上述计算过程会丢失maxIndex右边的水坑，用从右到左的遍历补回
        int curRightHeight=height[height.size()-1],tempVolumeR=0;
        for(int i=height.size()-1;i>=maxIndex;i--){
            if(height[i]>=curRightHeight){
                ans+=tempVolumeR;
                tempVolumeR=0;
                curRightHeight=height[i];
            }else{
                tempVolumeR+=curRightHeight-height[i];
            }
        }
        return ans;
    }
};

//栈 解法
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
//双指针 解法
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

// 可读性高的解法 求出每个位置，左右可能存在的最大值
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);
        int l = -1, r = -1;
        for(int i = 0; i < n; i ++){
            leftMax[i] = l;
            rightMax[n-1-i] = r;
            l = max(l, height[i]);
            r = max(r, height[n-1-i]);
        }
        for(int i = 0; i < n; i ++){
            res += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }
        return res;
    }
};

