 /*
 * 128. 最长连续序列
 * 给定一个未排序的整数数组，O(n)内找出最长连续序列的长度
 * 难度：中等
 * 分类：数组 集合
 * 算法：先保存所有数到集合当中，然后遍历数组，对数组元素，若没被集合判断过，则向两边延伸，并逐个erase。最终即可完整判断一边所有连续序列
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num:nums)
            s.insert(num);
        int ans=0;
        for(auto num:nums){
            if(s.count(num)>0){
                int len=1;
                int r=num+1;
                while(s.count(r)){
                    len++;
                    s.erase(r);
                    r++;
                }
                int l=num-1;
                while(s.count(l)){
                    len++;
                    s.erase(l);
                    l--;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
