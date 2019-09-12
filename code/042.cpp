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
