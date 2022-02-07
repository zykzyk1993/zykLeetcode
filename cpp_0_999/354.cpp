/*
 * 354. 俄罗斯套娃信封问题
 * 题意：给定一堆信封，当信封长宽都小于另一个时，可以被放入，求最大套娃数量
 * 难度：困难
 * 分类：贪心 dp
 * 算法：按照第一维正序，同时第二维逆序排列，然后转化为第二维的最长上升子序列问题
 */
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()){
            return 0;
        }

        vector<int> dp = vector<int>(envelopes.size(), 0);
        int result = 0;

        sort(envelopes.begin(), envelopes.end());


        for (int i = 0; i < dp.size();i++){
            if(i==0){
                dp[i] = 1;
                result = 1;
                continue;
            }else{
                int maxvalue = 0;
                for (int j = 0; j <i;j++){
                    if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                        maxvalue = max(maxvalue, dp[j]);
                    }

                }
                dp[i] = maxvalue + 1;
                result = max(dp[i], result);
            }
        }

            return result;
    }
};


//二分优化版本
bool mycmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),mycmp);
        vector<int> tmp;
        for(int i=0;i<envelopes.size();i++){
            auto cur=lower_bound(tmp.begin(),tmp.end(),envelopes[i][1]);
            if(cur==tmp.end()) tmp.push_back(envelopes[i][1]);
            else *cur=envelopes[i][1];
        }
        return tmp.size();
    }
};
