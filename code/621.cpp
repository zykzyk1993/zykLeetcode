class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        int l=tasks.size(),maxCnt=0;
        for(auto c:tasks){
            cnt[c-'A']++;
            maxCnt=max(maxCnt,cnt[c-'A']);
        }
        int maxCntChar=0;
        for(int i=0;i<26;i++){
            if(cnt[i]==maxCnt)maxCntChar++;
        }
        return max((maxCnt-1)*(n+1)+maxCntChar,l);
    }
};
