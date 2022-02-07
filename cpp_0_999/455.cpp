/*
 * 455. 分发饼干
 * 题意：饼干数组和孩子胃口数组，尽量满足尽可能多的孩子
 * 难度：简单
 * 分类：贪心
 * 算法：将饼干和胃口排序，逐个满足，否则只能挑更大的饼干
 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0,j=0,res=0;
        while(i<g.size()&&j<s.size()){
            if(g[i]<=s[j]){
                res++;
                i++;
            }
            j++;
        }
        return res;
    }
};
